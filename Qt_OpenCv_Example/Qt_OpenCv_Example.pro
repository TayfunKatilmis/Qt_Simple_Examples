QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\opencv\build\include

LIBS += C:\opencv\build\bin\libopencv_core453.dll
LIBS += C:\opencv\build\bin\libopencv_highgui453.dll
LIBS += C:\opencv\build\bin\libopencv_imgcodecs453.dll
LIBS += C:\opencv\build\bin\libopencv_imgproc453.dll
LIBS += C:\opencv\build\bin\libopencv_features2d453.dll
LIBS += C:\opencv\build\bin\libopencv_calib3d453.dll
LIBS += C:\opencv\build\bin\libopencv_flann453.dll
LIBS += C:\opencv\build\bin\libopencv_ml453.dll
LIBS += C:\opencv\build\bin\libopencv_objdetect453.dll
LIBS += C:\opencv\build\bin\libopencv_video453.dll
LIBS += C:\opencv\build\bin\libopencv_videoio453.dll
LIBS +=-L:/Apps_Installation_Folder/opencv/build/lib

RESOURCES += \
    images.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world453
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world453d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world453

INCLUDEPATH += $$PWD/../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../opencv/build/include
