/**
 * Client.java
 * 全民大讨论聊天室——客户端
 * @author CresCent-Charles
 * @version 1.0, 06/01/2023
 */

package client;

import java.io.IOException;

public class Client
{
    /**
     * 主函数
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException
    {
        //打开客户端界面
        client.MyJPanel mjp = new client.MyJPanel("全民大讨论聊天客户端");
        //按钮响应
        mjp.respond();
    }
}

