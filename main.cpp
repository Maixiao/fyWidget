#include "Widget.h"

#include <QApplication>
#include <QLockFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QString path = QDir::temp().absoluteFilePath("SingleApp.lock");
    QLockFile lockFile(path);

    bool isLock = lockFile.isLocked();
    (void)isLock; // 没什么实际意义
    // tryLock尝试创建锁定文件。此函数如果获得锁，则返回true; 否则返回false。
    // 如果另一个进程（或另一个线程）已经创建了锁文件，则此函数将最多等待timeout毫秒
    if (!lockFile.tryLock(100))
    {
        return 0;
    }
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
