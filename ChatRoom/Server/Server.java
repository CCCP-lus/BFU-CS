/**
 * Server.java
 * 全民大讨论聊天室——服务器
 * @author CresCent-Charles
 * @version 1.0, 06/01/2023
 */

package Server;

import User.*;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.StringTokenizer;

public class Server
{
    //窗口元素
    private JFrame myJF;                //容器
    private JTextArea all_WORD;         //公屏内容
    private JTextField edit_WORD;       //打字内容
    private JTextField tf_max;          //最大人数文本框
    private JTextField tf_port;         //端口号文本框
    private JButton TURN_ON;            //开启服务器按钮
    private JButton TURN_OFF;           //关闭服务器按钮
    private JButton SEND;               //发送文字按钮
    private DefaultListModel listModel; //在线成员列表

    //他类组件
    private final MyTimer myTimer;      //计时器

    //功能标志
    private boolean isStart = false;    //标志服务器开启状态
    private int MAX = 30;               //人数上限

    //成员变量
    private ServerSocket serverSocket;
    private Anteroom serverThread;
    private ArrayList<Receiver> clients;

    /**
     * 主方法
     * @param args
     */
    public static void main(String[] args)
    {
        new Server();
    }

    /**
     * 构造函数
     */
    public Server()
    {
        Init();

        //开始计时
        myTimer = new MyTimer();
        myTimer.setDaemon(true);    //设置守护线程
        myTimer.start();

        // 关闭窗口时事件
        myJF.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                if (isStart) {
                    closeServer();
                }
                System.exit(0);
            }
        });

        //文本框按回车键、单机发送按钮都可以发送文本
        edit_WORD.addActionListener(e ->
        {
            try
            {
                send();
            }
            catch (IOException ex)
            {
                throw new RuntimeException(ex);
            }
        });
        SEND.addActionListener(arg0 ->
        {
            try
            {
                send();
            }
            catch (IOException e)
            {
                throw new RuntimeException(e);
            }
        });

        //启动服务器
        TURN_ON.addActionListener(e ->
        {
            //禁止重复开启
            if (isStart)
            {
                JOptionPane.showMessageDialog(myJF, "服务器已处于启动状态，不要重复启动！","错误", JOptionPane.ERROR_MESSAGE);
                return;
            }

            int max, port;

            //鲁棒性检测
            try
            {
                try
                {
                    max = Integer.parseInt(tf_max.getText());
                }
                catch (Exception e1)
                {
                    throw new Exception("人数上限为正整数！");
                }
                if (max <= 0)
                {
                    throw new Exception("人数上限为正整数！");
                }
                try
                {
                    port = Integer.parseInt(tf_port.getText());
                }
                catch (Exception e1)
                {
                    throw new Exception("端口号为正整数！");
                }
                if (port <= 0)
                {
                    throw new Exception("端口号为正整数！");
                }

                //打开服务器
                serverStart(max, port);
                all_WORD.append("服务器已成功启动!人数上限：" + max + ",端口：" + port + "\r\n");
                JOptionPane.showMessageDialog(myJF, "服务器成功启动!");

                //开始巡检
                Inspection inspection = new Inspection();
                inspection.setDaemon(true);
                inspection.start();

                //修改组件状态
                TURN_ON.setEnabled(false);
                tf_max.setEnabled(false);
                MAX = max;
                tf_port.setEnabled(false);
                TURN_OFF.setEnabled(true);
            }
            catch (Exception exc)
            {
                JOptionPane.showMessageDialog(myJF, exc.getMessage(),"错误", JOptionPane.ERROR_MESSAGE);
            }
        });

        // 单击停止服务器按钮时事件
        TURN_OFF.addActionListener(e ->
        {
            if (!isStart)
            {
                JOptionPane.showMessageDialog(myJF, "服务器还未启动，无需停止！", "错误", JOptionPane.ERROR_MESSAGE);
                return;
            }
            try
            {
                closeServer();
                TURN_ON.setEnabled(true);
                tf_max.setEnabled(true);
                tf_port.setEnabled(true);
                TURN_OFF.setEnabled(false);
                all_WORD.append("服务器成功停止!\r\n");
                isStart = false;
                JOptionPane.showMessageDialog(myJF, "服务器成功停止！");
            }
            catch (Exception exc)
            {
                JOptionPane.showMessageDialog(myJF, "停止服务器发生异常！", "错误", JOptionPane.ERROR_MESSAGE);
            }
        });
    }

    /**
     * 初始化服务器界面
     */
    void Init()
    {
        //组件初始化
        myJF = new JFrame("全民大讨论聊天服务器");
        all_WORD = new JTextArea();
        all_WORD.setEditable(false);
        all_WORD.setForeground(Color.blue);
        edit_WORD = new JTextField();
        tf_max = new JTextField("30");
        tf_port = new JTextField("8888");
        TURN_ON = new JButton("启动");
        TURN_OFF = new JButton("停止");
        SEND = new JButton("发送");
        TURN_OFF.setEnabled(false);
        listModel = new DefaultListModel();
        JList userList = new JList(listModel);

        //打字区配置
        JPanel southPanel = new JPanel(new BorderLayout());
        southPanel.setBorder(new TitledBorder("写消息"));
        southPanel.add(edit_WORD, "Center");
        southPanel.add(SEND, "East");

        //在线列表区配置
        JScrollPane leftPanel = new JScrollPane(userList);
        leftPanel.setBorder(new TitledBorder("在线用户"));

        //公屏配置
        JScrollPane rightPanel = new JScrollPane(all_WORD);
        rightPanel.setBorder(new TitledBorder("消息显示区"));

        //中间区域的左右分屏
        JSplitPane centerSplit = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, rightPanel);
        centerSplit.setDividerLocation(100);

        //操作区配置
        JPanel northPanel = new JPanel();
        northPanel.setLayout(new GridLayout(1, 6));
        northPanel.add(new JLabel("人数/上限"));
        northPanel.add(tf_max);
        northPanel.add(new JLabel("端口"));
        northPanel.add(tf_port);
        northPanel.add(TURN_ON);
        northPanel.add(TURN_OFF);
        northPanel.setBorder(new TitledBorder("配置信息"));

        //添加到窗体
        myJF.setLayout(new BorderLayout());
        myJF.add(northPanel, "North");
        myJF.add(centerSplit, "Center");
        myJF.add(southPanel, "South");
        myJF.setSize(600, 400);
        int screen_width = Toolkit.getDefaultToolkit().getScreenSize().width;
        int screen_height = Toolkit.getDefaultToolkit().getScreenSize().height;
        myJF.setLocation((screen_width - myJF.getWidth()) / 2,
                (screen_height - myJF.getHeight()) / 2);
        myJF.setVisible(true);
    }

    /**
     * 群发服务器的消息
     * @throws IOException
     */
    public void send() throws IOException
    {
        //服务器关闭状态
        if (!isStart)
        {
            JOptionPane.showMessageDialog(myJF, "服务器还未启动,不能发送消息！", "错误", JOptionPane.ERROR_MESSAGE);
            return;
        }
        //没有在线用户
        if (clients.size() == 0)
        {
            JOptionPane.showMessageDialog(myJF, "没有用户在线,不能发送消息！", "错误", JOptionPane.ERROR_MESSAGE);
            return;
        }

        //读取消息并判定非空
        String message = edit_WORD.getText().trim();
        if (message == null || message.equals(""))
        {
            JOptionPane.showMessageDialog(myJF, "消息不能为空！", "错误", JOptionPane.ERROR_MESSAGE);
            return;
        }

        //群发服务器消息
        sendServerMessage(message);
        all_WORD.append("[系统消息:" + myTimer.getTime() + "]" + edit_WORD.getText() + "\r\n");
        edit_WORD.setText(null);
    }

    /**
     * 启动服务器
     * @param max 最大在线人数
     * @param port 端口号
     * @throws java.net.BindException
     */
    public void serverStart(int max, int port) throws java.net.BindException
    {
        try
        {
            clients = new ArrayList<Receiver>();
            serverSocket = new ServerSocket(port);
            serverThread = new Anteroom(serverSocket, max);
            serverThread.start();
            isStart = true;
        }
        catch (BindException e)
        {
            isStart = false;
            throw new BindException("端口号已被占用，请换一个！");
        }
        catch (Exception e1)
        {
            e1.printStackTrace();
            isStart = false;
            throw new BindException("启动服务器异常！");
        }
    }

    /**
     * 关闭服务器
     */
    @SuppressWarnings("deprecation")//防报错
    public void closeServer()
    {
        try
        {
            //停止服务器线程
            if (serverThread != null)
                serverThread.interrupt();

            //给所有在线用户发送关闭命令，关闭与客户端的连接，从list里移除
            for (int i = clients.size() - 1; i >= 0; i--)
            {
                clients.get(i).getDout().writeUTF("CLOSE");
                clients.get(i).getDout().flush();
                clients.get(i).interrupt();
                clients.get(i).getDin().close();
                clients.get(i).getDout().close();
                clients.get(i).socket.close();
                clients.remove(i);
            }

            //关闭服务器端连接
            if (serverSocket != null)
            {
                serverSocket.close();
            }

            //清屏
            listModel.removeAllElements();
            isStart = false;
        }
        catch (IOException e)
        {
            e.printStackTrace();
            isStart = true;
        }
    }

    /**
     * 群发服务器消息
     * @param message 准备群发的消息
     * @throws IOException
     */
    public void sendServerMessage(String message) throws IOException
    {
        //先特殊判定是否为踢出成员
        String[] temp = message.split("@");
        if(temp.length == 2 && temp[0].equals("kickout"))
        {

            for(int i = clients.size() - 1; i >= 0; i--)
            {
                if(clients.get(i).getUser().getName().equals(temp[1]))
                {
                    //更新在线列表和计数
                    listModel.removeElement(clients.get(i).getUser().getName());
                    tf_max.setText(listModel.size() + "/" + MAX);
                    clients.get(i).getDout().writeUTF("KICK");
                    clients.get(i).getDout().flush();
                    clients.get(i).interrupt();
                    clients.get(i).getDin().close();
                    clients.get(i).getDout().close();
                    clients.get(i).socket.close();
                    clients.remove(i);
                    return ;
                }
            }
        }

        //向所有在线用户发送消息
        for (int i = clients.size() - 1; i >= 0; i--)
        {
            clients.get(i).getDout().writeUTF("服务器[" + myTimer.getTime() + "]：" + message);
            clients.get(i).getDout().flush();
        }
    }


    /**
     * 用于巡检已登录客户端的状态，及时清除断开连接的客户
     */
    class Inspection extends Thread
    {
        Inspection()
        {

        }

        public void run()
        {
            while(isStart)
            {
                for(int i = 0; i < clients.size(); i++)
                {
                    try
                    {
                        //发送问询消息
                        clients.get(i).getDout().writeUTF("EXIST");
                        String respond = clients.get(i).getDin().readUTF();

                        //如果未收到指定回复
                        if(!respond.equals("RUNNING"))
                        {
                            clients.get(i).interrupt();
                            clients.get(i).getDin().close();
                            clients.get(i).getDout().close();
                            clients.get(i).socket.close();
                            clients.remove(i);
                        }

                    }
                    catch (IOException e)
                    {
                        throw new RuntimeException(e);
                    }

                    try
                    {
                        sleep(1000);
                    } catch (InterruptedException e)
                    {
                        throw new RuntimeException(e);
                    }
                }
            }
        }
    }

    /**
     * 用于接收管理员的指令，控制服务器端
     */
    class Control extends Thread
    {
        /*
        该部分代码的功能最终由图形界面实现
         */
    }

    /**
     * 专门用于等候新的聊客连接并建立通信通道
     */
    class Anteroom extends Thread
    {
        private ServerSocket serverSocket;
        private int max;

        /**
         * 等候聊客类的构造函数
         * @param serverSocket 一个服务器接收端参数
         * @param max 最大人数限制
         */
        public Anteroom(ServerSocket serverSocket, int max)
        {
            this.serverSocket = serverSocket;
            this.max = max;
        }

        public void run()
        {
            while (isStart)
            {
                try
                {
                    //接受客户端socket请求
                    Socket socket = serverSocket.accept();

                    //服务器达到最大连接
                    if (clients.size() == max)
                    {
                        InputStream inputStream = socket.getInputStream();//字节输入流
                        DataInputStream dataInputStream = new DataInputStream(inputStream);//数据输入流

                        OutputStream outputStream = socket.getOutputStream();//字节输出流
                        DataOutputStream dataOutputStream = new DataOutputStream(outputStream);//数据输出流

                        //接收客户端的基本用户信息
                        String inf = dataInputStream.readUTF();
                        StringTokenizer st = new StringTokenizer(inf, "@");
                        User user = new User(st.nextToken(), st.nextToken());

                        //反馈连接成功信息
                        dataOutputStream.writeUTF("MAX@服务器：对不起，" + user.getName() + user.getIp() + "，服务器在线人数已达上限，请稍后尝试连接！");
                        dataOutputStream.flush();

                        //释放资源
                        dataInputStream.close();
                        dataOutputStream.close();
                        socket.close();
                        continue;
                    }

                    //创建并开启对此客户端服务的线程
                    Receiver client = new Receiver(socket);

                    //判断重名
                    int t;
                    for(t = 0; t < clients.size(); t++)
                    {
                        if(Objects.equals(clients.get(t).getUser().getName(), client.getUser().getName()))
                        {
                            client.getDout().writeUTF("SAME@服务器：对不起，" + client.getUser().getName() + client.getUser().getIp() + "，服务器已有重名用户，请更改姓名后连接！");
                            client.getDout().flush();
                            break;
                        }
                    }

                    //新建客户端服务线程并开始运行
                    if(t == clients.size())
                    {
                        client.start();

                        //更新在线状态
                        clients.add(client);
                        listModel.addElement(client.getUser().getName());
                        all_WORD.append("[" + myTimer.getTime() + "]欢迎" + client.getUser().getName() + "进入聊天室!\r\n");

                        //除其本身外，群发上线信息
                        for (int i = clients.size() - 1; i >= 0; i--)
                        {
                            if(clients.get(i).socket != socket)
                            {
                                clients.get(i).getDout().writeUTF("[" + myTimer.getTime() + "]欢迎" + client.getUser().getName() + "进入聊天室!\r");
                                clients.get(i).getDout().flush();
                            }
                        }

                        //计数器更新
                        tf_max.setText(listModel.size() + "/" + MAX);
                    }

                }
                catch (IOException e)
                {
//                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * 用于接收特定客户端的信息
     */
    class Receiver extends Thread
    {
        private Socket socket;
        private DataInputStream din;
        private DataOutputStream dout;
        private User user;

        public DataOutputStream getDout()
        {
            return dout;
        }

        public DataInputStream getDin()
        {
            return din;
        }

        /**
         * 构造函数
         * @param socket 提出访问请求的客户端socket
         */
        public Receiver(Socket socket)
        {
            try
            {
                //初始化
                this.socket = socket;
                InputStream inputStream = this.socket.getInputStream();//字节输入流
                din = new DataInputStream(inputStream);//数据输入流
                String text = din.readUTF();//获取输入的信息

                OutputStream outputStream = this.socket.getOutputStream();//字节输出流
                dout = new DataOutputStream(outputStream);//数据输出流

                //收集拼接用户对象
                StringTokenizer st = new StringTokenizer(text, "@");
                user = new User(st.nextToken(), st.nextToken());

                //反馈连接成功信息
                dout.writeUTF(user.getName() + user.getIp() + "与服务器连接成功!");
                dout.flush();

                //更新在线用户信息
                if (clients.size() > 0)
                {
                    String temp = "";
                    for (int i = clients.size() - 1; i >= 0; i--)
                    {
                        temp += (clients.get(i).getUser().getName() + "/" + clients.get(i).getUser().getIp()) + "@";
                    }

                    //像客户端发送当前用户名单，更新客户端列表
                    dout.writeUTF("USERLIST@" + clients.size() + "@" + temp);
                    dout.flush();
                }

                //广播上线命令（包括自身）
                for (int i = clients.size() - 1; i >= 0; i--)
                {
                    clients.get(i).getDout().writeUTF("ADD@" + user.getName() + user.getIp());
                    clients.get(i).getDout().flush();
                }

            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }

        public User getUser()
        {
            return user;
        }

        public void run()
        {
            String message = null;
            while (true)
            {
                try
                {
                    //接收并分析来自客户端的消息
                    try
                    {
                        message = din.readUTF();
                    }
                    catch (SocketException ee)
                    {
//                        ee.printStackTrace();
                    }

                    if(message == null)
                        continue;
                    //客户端下线
                    if (message.equals("CLOSE"))
                    {
                        all_WORD.append(this.getUser().getName() + this.getUser().getIp() + "下线!\r\n");

                        //向所有用户广播下线通知（不包括自身）
                        for (int i = clients.size() - 1; i >= 0; i--)
                        {
                            if(clients.get(i).socket != socket)
                            {
                                clients.get(i).getDout().writeUTF("[" + myTimer.getTime() + "]欢送" + this.getUser().getName() + "离开聊天室!\r");
                                clients.get(i).getDout().flush();
                            }
                        }

                        //断开连接释放资源
                        din.close();
                        dout.close();
                        socket.close();

                        //广播该用户的下线命令，让在线用户更新列表
                        for (int i = clients.size() - 1; i >= 0; i--)
                        {
                            try
                            {
                                clients.get(i).getDout().writeUTF("DELETE@" + user.getName());
                                clients.get(i).getDout().flush();
                            }
                            catch (SocketException e)
                            {

                            }
                        }

                        //更新在线列表和计数
                        listModel.removeElement(user.getName());
                        tf_max.setText(listModel.size() + "/" + MAX);

                        // 删除此条客户端服务线程
                        for (int i = clients.size() - 1; i >= 0; i--)
                        {
                            if (clients.get(i).getUser() == user)
                            {
                                Receiver temp = clients.get(i);
                                clients.remove(i);
                                temp.interrupt();
                                return;
                            }
                        }
                    }
                    else
                    {
                        //拆解命令为三部分：发送者、目标、内容（目标本想做私聊功能，可惜时间不允许）
                        StringTokenizer stringTokenizer = new StringTokenizer(message, "/@");
                        String source = stringTokenizer.nextToken();
                        String owner = stringTokenizer.nextToken();
                        String content = stringTokenizer.nextToken();

                        //合并为标准发送格式
                        message = "[" + source + "：" + myTimer.getTime() + "]" + content;
                        all_WORD.append(message + "\r\n");

                        //群发消息
                        if (owner.equals("ALL"))
                        {
                            for (int i = clients.size() - 1; i >= 0; i--)
                            {
                                clients.get(i).getDout().writeUTF(message);
                                clients.get(i).getDout().flush();
                            }
                        }
                    }
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * 用于发送特定客户端的信息
     */
    class Sender extends Thread
    {
        /*
        此部分由按钮事件实现
         */
    }

}
