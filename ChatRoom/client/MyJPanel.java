/**
 * MyJPanel.java
 * 全民大讨论聊天室——客户端界面
 * @author CresCent-Charles
 * @version 1.0, 06/01/2023
 */

package client;

import User.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class MyJPanel extends JPanel
{
    //窗口元素
    JFrame myJF = new JFrame();         //容器
    JPanel operation;                   //操作区
    JTextField tf_IP;                   //IP文本框
    JLabel la_IP;                       //IP文本标签
    JTextField tf_PORT;                 //端口文本框
    JLabel la_PORT;                     //端口文本标签
    JTextField tf_NAME;                 //昵称文本框
    JLabel la_NAME;                     //昵称文本标签
    JButton ENTER;                      //进入聊天室按钮
    JButton EXIT;                       //退出聊天室按钮
    JPanel talking;                     //讨论区
    JTextArea all_WORD;                 //公屏内容
    JPanel chatting;                    //打字区
    JTextArea edit_WORD;                //打字内容
    JButton SEND;                       //发送按钮

    //功能标志
    static boolean isConnected = false;//标志连接成功与否

    //成员变量
    Socket socket;
    DataInputStream din;
    DataOutputStream dout;
    Receiver receiver;
    Map<String, User> onlineUsers = new HashMap<>();    //存目前在线的用户信息（判断重名用）


    /**
     * 构造函数
     * @param s 按课设要求的窗口命名
     * @throws IOException
     */
    public MyJPanel(String s) throws IOException
    {
        //初始化界面
        this.init(s);
    }

    /**
     * 初始化客户端界面的函数
     * @param s 按课设要求的窗口命名
     */
    public void init(String s)
    {
        //窗口配置
        myJF.setTitle(s);
        myJF.setSize(650, 500);
        myJF.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        myJF.setLocationRelativeTo(null);

        //操作区配置
        operation = new JPanel();
        la_IP = new JLabel("IP: ", SwingConstants.LEFT);
        tf_IP = new JTextField();
        la_PORT = new JLabel("端口: ", SwingConstants.LEFT);
        tf_PORT = new JTextField();
        la_NAME = new JLabel("昵称: ", SwingConstants.LEFT);
        tf_NAME = new JTextField();
        ENTER = new JButton("进入聊天室");
        EXIT = new JButton("退出聊天室");
        operation.setLayout(new GridBagLayout());
//        operation.setBackground(Color.decode("#1D6A96"));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        gbc.insets = new Insets(0,0,0,0);
        gbc.weighty = 0;
        gbc.gridwidth = 1;
        gbc.weightx = 0.4;
        gbc.gridx = 0;
        gbc.gridy = 0;
        operation.add(la_IP, gbc);
        gbc.gridwidth = 1;
        gbc.weightx = 1.6;
        gbc.gridx = 1;
        gbc.gridy = 0;
        operation.add(tf_IP, gbc);
        tf_IP.setText("127.0.0.1");
        gbc.gridwidth = 1;
        gbc.weightx = 0.4;
        gbc.gridx = 2;
        gbc.gridy = 0;
        operation.add(la_PORT, gbc);
        gbc.gridwidth = 1;
        gbc.weightx = 1.6;
        gbc.gridx = 3;
        gbc.gridy = 0;
        operation.add(tf_PORT, gbc);
        tf_PORT.setText("8888");
        gbc.gridwidth = 1;
        gbc.weightx = 0.4;
        gbc.gridx = 4;
        gbc.gridy = 0;
        operation.add(la_NAME, gbc);
        gbc.gridwidth = 1;
        gbc.weightx = 1.6;
        gbc.gridx = 5;
        gbc.gridy = 0;
        operation.add(tf_NAME, gbc);
        gbc.gridwidth = 1;
        gbc.weightx = 0.8;
        gbc.gridx = 6;
        gbc.gridy = 0;
        operation.add(ENTER, gbc);
        ENTER.setEnabled(true);
        gbc.gridx = 7;
        gbc.gridy = 0;
        operation.add(EXIT, gbc);
        EXIT.setEnabled(false);
        gbc.gridx = 8;
        gbc.gridy = 0;

        //讨论区配置
        talking = new JPanel(new GridBagLayout());
        GridBagConstraints gbc3 = new GridBagConstraints();
        gbc3.weightx = 1.0;
        gbc3.weighty = 1;
        gbc3.fill = GridBagConstraints.BOTH;
        gbc3.insets = new Insets(0,0,0,0);
        all_WORD = new JTextArea();
        all_WORD.setLineWrap(true);        //自动换行
        all_WORD.setWrapStyleWord(true);
        all_WORD.setEnabled(false);
        all_WORD.setDisabledTextColor(Color.black);
//        all_WORD.setBackground(Color.decode("#85B8C8"));
        JScrollPane scrollPane = new JScrollPane(all_WORD);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        talking.add(scrollPane, gbc3);

        //打字区配置
        chatting = new JPanel();
        chatting.setLayout(new GridBagLayout());
        edit_WORD = new JTextArea("");
        edit_WORD.setLineWrap(true);        //自动换行
        edit_WORD.setWrapStyleWord(true);
        edit_WORD.setEnabled(false);
//        edit_WORD.setBackground(Color.decode("#D1DDDB"));
        JScrollPane scrollPane2 = new JScrollPane(edit_WORD);
        SEND = new JButton("发送");
        SEND.setEnabled(false);
        GridBagConstraints gbc2 = new GridBagConstraints();
        gbc2.fill = GridBagConstraints.BOTH;
        gbc2.insets = new Insets(0,0,0,0);
        gbc2.gridheight = 1;
        gbc2.weighty = 1;
        gbc2.gridwidth = 1;
        gbc2.weightx = 1.8;
        gbc2.gridx = 0;
        gbc2.gridy = 0;
        chatting.add(scrollPane2, gbc2);
        gbc2.gridwidth = 1;
        gbc2.weightx = 0.2;
        gbc2.gridx = 1;
        gbc2.gridy = 0;
        chatting.add(SEND, gbc2);

        //布局设定
        myJF.setLayout(new BorderLayout());
        myJF.add(operation, BorderLayout.NORTH);
        operation.setPreferredSize(new Dimension(myJF.getWidth(), (int)(myJF.getHeight() * 0.1)));
        myJF.add(talking, BorderLayout.CENTER);
        talking.setPreferredSize(new Dimension(myJF.getWidth(), (int)(myJF.getHeight() * 0.7)));
        myJF.add(chatting, BorderLayout.SOUTH);
        chatting.setPreferredSize(new Dimension(myJF.getWidth(), (int)(myJF.getHeight() * 0.2)));
        myJF.setVisible(true);
    }

    /**
     * 实现按钮、文本框等组件的事件监听
     */
    public void respond()
    {
        //按钮状态初始化
        ENTER.setEnabled(true);
        ENTER.setFocusable(false);
        EXIT.setEnabled(false);
        EXIT.setFocusable(true);

        //连接按钮的事件
        ENTER.addActionListener(e ->
        {
            //重复连接
            if(isConnected)
            {
                JOptionPane.showMessageDialog(null, "链接两次要多收费哟!", "已在连接状态",JOptionPane.ERROR_MESSAGE);
            }
            //过程检测
            else
            {
                int port;

                //连接服务器的判定
                try
                {
                    //获取port, ip, name
                    try
                    {
                        port = Integer.parseInt(tf_PORT.getText().trim());
                    }
                    catch (NumberFormatException ee)
                    {
                        throw new Exception("端口号应为整数");
                    }
                    String ip = tf_IP.getText().trim();
                    String name = tf_NAME.getText().trim();

                    //信息为空
                    if(name.equals("") || ip.equals(""))
                    {
                        throw new Exception("个人信息不能为空");
                    }

                    //尝试连接，检测暂存与服务器连接状态
                    boolean flag = connect(String.valueOf(port), ip, name);
                    if(!flag)
                    {
                        throw new Exception("连接失败");
                    }

                    //更新按钮状态
                    ENTER.setEnabled(false);
                    ENTER.setFocusable(true);
                    EXIT.setEnabled(true);
                    EXIT.setFocusable(false);
                    SEND.setEnabled(true);
                    SEND.setFocusable(false);
                    edit_WORD.setEnabled(true);

                    //提示消息
//                    if(isConnected)
//                        JOptionPane.showMessageDialog(null, "请畅所欲言吧!");
                }
                catch (Exception eee)
                {
                    JOptionPane.showMessageDialog(this, eee.getMessage(), "出错", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        //退出按钮的事件
        EXIT.addActionListener(e ->
        {
            //重复断开
            if(!isConnected)
            {
                JOptionPane.showMessageDialog(null, "断开两次也不便宜哟!", "已在断开状态",JOptionPane.ERROR_MESSAGE);
            }
            else
            {
                try
                {
                    //尝试断开，检测暂存与服务器连接状态
                    boolean flag = close();
                    if(!flag)
                    {
                        throw new Exception("断开时异常");
                    }

                    //更新按钮状态
                    EXIT.setEnabled(false);
                    EXIT.setFocusable(true);
                    ENTER.setEnabled(true);
                    ENTER.setFocusable(false);
                    SEND.setEnabled(false);
                    SEND.setFocusable(true);
                    edit_WORD.setEnabled(false);

                    //提示消息
                    JOptionPane.showMessageDialog(null, "期待您下次来");
                }
                catch (Exception ee)
                {
                    JOptionPane.showMessageDialog(this, ee.getMessage(), "出错", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        //发送按钮的事件
        SEND.addActionListener(e ->
        {
            //未连接不许发言
            if(!isConnected)
            {
                JOptionPane.showMessageDialog(null, "发言之前要先链接!", "已在断开状态",JOptionPane.ERROR_MESSAGE);
            }
            else
            {
                String message = edit_WORD.getText().trim();

                //空内容不许发送
                if(message == null || message.equals(""))
                {
                    JOptionPane.showMessageDialog(null, "不能发送空内容!", "",JOptionPane.WARNING_MESSAGE);
                }
                //群发消息并更新文本域
                else
                {
                    try 
                    {
                        dout.writeUTF(tf_NAME.getText() + "@ALL@" + message);
                        dout.flush();
                    } 
                    catch (IOException ex) 
                    {
                        throw new RuntimeException(ex);
                    }
                    edit_WORD.setText("");
                }
            }
        });

        //关闭窗口的事件
        myJF.addWindowListener(
                new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e)
                    {
                        //继承
                        super.windowClosing(e);
                        //若还在连接状态则关闭连接，然后退出
                        if(isConnected)
                            close();
                        System.exit(0);
                    }
                });
    }

    /**
     * 连接客户端的函数
     * @param port 客户端的端口号
     * @param ip 客户端的IP
     * @param name 客户端的昵称
     * @return
     */
    public boolean connect(String port, String ip, String name)
    {
        try
        {
            //通过port和ip建立socket，初始化dout和din
            socket = new Socket(ip, Integer.parseInt(port));
            InputStream inputStream = this.socket.getInputStream();//字节输入流
            din = new DataInputStream(inputStream);//数据输入流
            OutputStream outputStream = this.socket.getOutputStream();//字节输出流
            dout = new DataOutputStream(outputStream);//数据输出流

            //进行重名检测，反馈同名的异常数据，修改连接状态
            if(onlineUsers.get(name) != null)
            {
                all_WORD.append("与端口号为：" + port + "，IP地址为：" + ip + "   的服务器连接失败!" + "\r\n");
                isConnected = false;
                return false;
            }
            //与服务器通信，确认登录完成后修改连接状态
            else
            {
                //向客户端发送登入信息
                dout.writeUTF(name + "@" + socket.getLocalAddress().toString());
                dout.flush();

                //打开接收线程
                receiver = new Receiver(din, all_WORD);
                receiver.start();

                //修改状态
                isConnected = true;
                return true;
            }

        }
        catch (Exception e)
        {
            all_WORD.append("与端口号为：" + port + "，IP地址为：" + ip + "   的服务器连接失败!" + "\r\n");
            isConnected = false;
            return false;
        }
    }

    /**
     * 客户端的客户端关闭函数（自己关闭）
     * 因为存在互斥变量（登入名单等），故使用synchronized加锁
     */
    public synchronized boolean close()
    {
        try
        {
            //发送关闭请求
            dout.writeUTF("CLOSE");
            dout.flush();

            //断开连接，并修改连接状态
            receiver.interrupt();
            if(din != null) din.close();
            if(dout != null) dout.close();
            if(socket != null) socket.close();
            isConnected = false;

            //更新按钮状态
            EXIT.setEnabled(false);
            EXIT.setFocusable(true);
            ENTER.setEnabled(true);
            ENTER.setFocusable(false);
            SEND.setEnabled(false);
            SEND.setFocusable(true);
            edit_WORD.setEnabled(false);

            return true;
        }
        catch (IOException e)
        {
            isConnected = true;
            return false;
        }
    }


    /**
     * 客户端的消息接收线程
     */
    public class Receiver extends Thread
    {
        DataInputStream din;
        JTextArea all_WORD;

        /**
         * 构造函数
         * @param din 读服务器传回的消息
         * @param all_WORD 公聊区文本域
         */
        Receiver(DataInputStream din, JTextArea all_WORD)
        {
            this.din = din;
            this.all_WORD = all_WORD;
        }

        /**
         * 服务器的客户端关闭函数（被关闭）
         * 因为存在互斥变量（登入名单等），故使用synchronized加锁
         * @throws IOException
         */
        public synchronized void Close() throws IOException
        {
            //只需要关闭相关资源
            if(din != null) din.close();
            if(dout != null) dout.close();
            if(socket != null) socket.close();

            //修改状态
            MyJPanel.isConnected = false;
        }

        public void run()
        {
            //当保持连接状态时
            while (isConnected)
            {
                String message = "";
                try
                {
                    //读取服务器的操作，用/@进行拆分提取出命令
                    message = din.readUTF();
                    StringTokenizer stringTokenizer = new StringTokenizer(message, "/@");
                    String command = stringTokenizer.nextToken();

                    /*
                    命令有八种，分别是：
                    1.CLOSE：客户端被服务器关闭
                    2.KICK：客户端被服务器踢出（和1只有提示不同）
                    3.EXIST：轮询应答，客户端需要回复指定内容，否则被踢出
                    4.ADD：有新用户上线，更新客户端list状态
                    5.DELETE：有用户下线，更新客户端list状态
                    6.USERLIST：保留的分支，原计划做在线用户的实时展示，后弃用
                    7.MAX：到达人数上限，拒绝接入
                    8.SAME：存在同名，拒绝接入
                     */

                    //客户端被服务器关闭
                    if (command.equals("CLOSE"))
                    {
                        all_WORD.append("客户端已被关闭\n");

                        //更新按钮状态
                        ENTER.setEnabled(false);
                        ENTER.setFocusable(true);
                        EXIT.setEnabled(false);
                        EXIT.setFocusable(true);
                        SEND.setEnabled(false);
                        SEND.setFocusable(true);
                        edit_WORD.setEnabled(false);
                        Close();

                        return;
                    }
                    //客户端被服务器踢出
                    else if(command.equals("KICK"))
                    {
                        all_WORD.append("您已被踢出群聊\n");

                        //更新按钮状态
                        ENTER.setEnabled(false);
                        ENTER.setFocusable(true);
                        EXIT.setEnabled(false);
                        EXIT.setFocusable(true);
                        SEND.setEnabled(false);
                        SEND.setFocusable(true);
                        edit_WORD.setEnabled(false);
                        Close();

                        return;
                    }
                    //轮询应答
                    else if(command.equals("EXIST"))
                    {
                        dout.writeUTF("RUNNING");
                    }
                    //有新用户上线
                    else if(command.equals("ADD"))
                    {
                        String username = "";
                        String userIp = "";

                        //加入在线列表中
                        if ((username = stringTokenizer.nextToken()) != null && (userIp = stringTokenizer.nextToken()) != null)
                        {
                            User user = new User(username, userIp);
                            onlineUsers.put(username, user);
                        }
                    }
                    //有用户下线
                    else if(command.equals("DELETE"))
                    {
                        String username = stringTokenizer.nextToken();
                        User user = onlineUsers.get(username);

                        //从在线列表中删除
                        onlineUsers.remove(user);
                    }
                    //（暂时弃用）加载在线用户列表
                    else if (command.equals("USERLIST"))
                    {
                        int size = Integer.parseInt(stringTokenizer.nextToken());
                        String username = null;
                        String userIp = null;
                        for (int i = 0; i < size; i++)
                        {
                            username = stringTokenizer.nextToken();
                            userIp = stringTokenizer.nextToken();
                            User user = new User(username, userIp);
                            onlineUsers.put(username, user);
                        }
                    }
                    //到达人数上限
                    else if (command.equals("MAX"))
                    {
                        all_WORD.append(stringTokenizer.nextToken() + stringTokenizer.nextToken() + "\r\n");
                        Close();
                        JOptionPane.showMessageDialog(null, "服务器拒绝了您的连接，请退出重试！", "错误", JOptionPane.ERROR_MESSAGE);

                        //更新按钮状态
                        ENTER.setEnabled(false);
                        ENTER.setFocusable(true);
                        EXIT.setEnabled(false);
                        EXIT.setFocusable(true);
                        SEND.setEnabled(false);
                        SEND.setFocusable(true);
                        edit_WORD.setEnabled(false);

                        return ;
                    }
                    // 存在重名用户
                    else if (command.equals("SAME"))
                    {
                        all_WORD.append(stringTokenizer.nextToken()
                                + stringTokenizer.nextToken() + "\r\n");
                        Close();
                        JOptionPane.showMessageDialog(null, "服务器已有同名用户，请退出重试！", "错误", JOptionPane.ERROR_MESSAGE);

                        //更新按钮状态
                        ENTER.setEnabled(false);
                        ENTER.setFocusable(true);
                        EXIT.setEnabled(false);
                        EXIT.setFocusable(true);
                        SEND.setEnabled(false);
                        SEND.setFocusable(true);
                        edit_WORD.setEnabled(false);

                        return;
                    }
                    //正常消息
                    else
                    {
                        all_WORD.append(message + "\n");
                    }
                }
                catch (IOException e)
                {
//                    e.printStackTrace();
                }
                catch (Exception e)
                {
//                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * 客户端的消息发送线程
     * 通过按钮事件实现了其功能
     */
//    public class Sender extends Thread
//    {
//
//
//    }
}