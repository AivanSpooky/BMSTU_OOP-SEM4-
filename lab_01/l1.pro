QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += sdk_no_version_check

LIBS += -lOpengl32 -lglu32


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action.cpp \
    action_manager.cpp \
    drawer.cpp \
    errors.cpp \
    figure.cpp \
    link.cpp \
    links.cpp \
    main.cpp \
    mainwindow.cpp \
    params.cpp \
    point.cpp \
    points.cpp

HEADERS += \
    action.h \
    action_manager.h \
    drawer.h \
    drawer_struct.h \
    errors.h \
    figure.h \
    link.h \
    links.h \
    mainwindow.h \
    params.h \
    point.h \
    point_struct.h \
    points.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
