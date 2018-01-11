#------------------------------------------------
# Project created by callen.cai
# mail:540276003#qq.com
# date:2018-01-01
#
#-------------------------------------------------

lessThan(QT_VERSION, "5.5.0") {
    error("Qt 5.5.0 or above is required.")
}

TEMPLATE = app

TARGET = QLauncher

QT += qml widgets

QML_IMPORT_PATH = $$PWD/qml

HEADERS += $$files($$PWD/src/*.h) \
           src/powerManager/PowerManager.h

SOURCES += $$files($$PWD/src/*.cpp) \
           src/powerManager/PowerManager.cpp
RESOURCES += resources.qrc

SUBDIRS += \
    src

exists(  $$PWD/../../device/rockchip/rk3399 ) {
DEFINES += PLATFORM_WAYLAND
message( "build $$TARGET with $$DEFINES support.")
  }

