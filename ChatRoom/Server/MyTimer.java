/**
 * MyTimer.java
 * 全民大讨论聊天室——计时器
 * @author CresCent-Charles
 * @version 1.0, 06/01/2023
 */

package Server;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class MyTimer extends Thread
{
    LocalTime time;

    public MyTimer()
    {

    }

    /**
     * 实时获取本机时间
     */
    @Override
    public void run()
    {
        while (true)
        {
            try
            {
                time = LocalTime.now();
                Thread.sleep(1000);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }

    /**
     * 获取指定输出形式的时间
     * @return HH:mm:ss格式的时间
     */
    public String getTime()
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return LocalTime.now().format(formatter);
    }
}
