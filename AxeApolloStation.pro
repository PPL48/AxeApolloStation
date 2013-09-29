#-------------------------------------------------
#
# Project created by QtCreator 2013-09-24T20:00:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AxeApolloStation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Includes/pesawat.cpp \
    Includes/penumpang.cpp \
    Includes/penerbangan.cpp \
    Includes/pemesan.cpp \
    Includes/pegawai.cpp \
    Includes/bandara.cpp \
    Includes/bagasi.cpp \
    Models/pesawatmodel.cpp \
    Models/penumpangmodel.cpp \
    Models/penerbanganmodel.cpp \
    Models/pemesanmodel.cpp \
    Models/pegawaimodel.cpp \
    Models/bandaramodel.cpp \
    Models/bagasimodel.cpp \
    viewfactory.cpp \
    Controllers/parkingcontroller.cpp \
    frmmanageflight.cpp \
    frmlogin.cpp \
    frmchoosecrew.cpp \
    frmchooseaviator.cpp \
    frmcheckin2.cpp \
    frmcheckin1.cpp

HEADERS  += mainwindow.h \
    Includes/pesawat.h \
    Includes/penumpang.h \
    Includes/penerbangan.h \
    Includes/pemesan.h \
    Includes/pegawai.h \
    Includes/bandara.h \
    Includes/bagasi.h \
    Models/pesawatmodel.h \
    Models/penumpangmodel.h \
    Models/penerbanganmodel.h \
    Models/pemesanmodel.h \
    Models/pegawaimodel.h \
    Models/bandaramodel.h \
    Models/bagasimodel.h \
    viewfactory.h \
    Controllers/parkingcontroller.h \
    frmmanageflight.h \
    frmlogin.h \
    frmchoosecrew.h \
    frmchooseaviator.h \
    frmcheckin2.h \
    frmcheckin1.h

FORMS    += mainwindow.ui \
    frmmanageflight.ui \
    frmlogin.ui \
    frmchoosecrew.ui \
    frmchooseaviator.ui \
    frmcheckin2.ui \
    frmcheckin1.ui
