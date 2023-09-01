/**
 * User.java
 * 全民大讨论聊天室——用户类
 * @author CresCent-Charles
 * @version 1.0, 06/01/2023
 */

package User;

public class User
{
    private String name;
    private String ip;

    public User(String name, String ip)
    {
        this.name = name;
        this.ip = ip;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getIp()
    {
        return ip;
    }

    public void setIp(String ip)
    {
        this.ip = ip;
    }
}