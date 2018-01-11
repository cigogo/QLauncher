#include "launcher.h"
#include "powerManager/PowerManager.h"
#include <QDebug>
#include<QTimer>
#include<QFile>
#include<QUrl>
Launcher::Launcher(QObject *parent) : QObject(parent)
{
}


void Launcher::slot_standby()
{
    system("echo mem > /sys/power/state");
}

void Launcher::pickWallpaper(QString path)
{
    if (path.isNull())
    {
        qDebug()<<"pickWallpaper path is null!"<<endl;
        return;
    }
    if (QFile::exists("/usr/local/QLauncher/background.jpg"))
    {
        QFile::remove("/usr/local/QLauncher/background.jpg");
    }

    bool result=QFile::copy(QUrl(path).toLocalFile(), "/usr/local/QLauncher/background.jpg");
        qDebug()<<"pickWallpaper path="<<QUrl(path).toLocalFile()<<",result="<<result;
}

void Launcher::powerControl()
{
    if(rk_get_screen_status())
    {
        qDebug()<<"key value is PowerKey, screen off ";
        rk_screen_off();
        QTimer::singleShot(100, this, SLOT(slot_standby()));
    }
    else
    {
        qDebug()<<"key value is PowerKey, screen ON ";
        rk_screen_on();
    }
}

void Launcher::emitNewIntent()
{
    emit newIntentReceived();
}

void Launcher::registerMethods()
{
    registerNativeMethods();
}

void Launcher::minimize()
{
    emit minimized();
}

void Launcher::registerNativeMethods()
{

}
