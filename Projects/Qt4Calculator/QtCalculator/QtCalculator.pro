#-------------------------------------------------
#
# Project created by QtCreator 2011-09-19T22:22:14
#
#-------------------------------------------------

QT += core gui
QT += widgets

TARGET = QtCalculator
TEMPLATE = app

INCLUDEPATH += interpreter/

SOURCES +=\
    interpreter/acosdfun.cpp \
    interpreter/acosrfun.cpp \
    interpreter/additiveexpr.cpp \
    interpreter/asindfun.cpp \
    interpreter/asinrfun.cpp \
    interpreter/atandfun.cpp \
    interpreter/atanrfun.cpp \
    interpreter/averagefun.cpp \
    interpreter/calculateengine.cpp \
    interpreter/calculatefunction.cpp \
    interpreter/clearrecordfun.cpp \
    interpreter/complex.cpp \
    interpreter/cosdfun.cpp \
    interpreter/cosrfun.cpp \
    interpreter/expfun.cpp \
    interpreter/factorialfun.cpp \
    interpreter/functionexpr.cpp \
    interpreter/functionmanager.cpp \
    interpreter/getrecordfun.cpp \
    interpreter/log10fun.cpp \
    interpreter/logfun.cpp \
    interpreter/multiplicativeexpr.cpp \
    interpreter/nonterminalexpr.cpp \
    interpreter/numberexpr.cpp \
    interpreter/powerfun.cpp \
    interpreter/primaryexpr.cpp \
    interpreter/recordfun.cpp \
    interpreter/rootfun.cpp \
    interpreter/saverecordfun.cpp \
    interpreter/sindfun.cpp \
    interpreter/sinrfun.cpp \
    interpreter/sumfun.cpp \
    interpreter/tandfun.cpp \
    interpreter/tanrfun.cpp \
    interpreter/terminalexpr.cpp \
    interpreter/token.cpp \
    interpreter/unaryexpr.cpp \
    mainwindow.cpp \
    main.cpp \
    questionedit.cpp \
    helpdialog.cpp \

HEADERS  += \
    helpdialog.h \
    interpreter/acosdfun.h \
    interpreter/acosrfun.h \
    interpreter/additiveexpr.h \
    interpreter/asindfun.h \
    interpreter/asinrfun.h \
    interpreter/atandfun.h \
    interpreter/atanrfun.h \
    interpreter/averagefun.h \
    interpreter/calculateengine.h \
    interpreter/calculatefunction.h \
    interpreter/clearrecordfun.h \
    interpreter/complex.h \
    interpreter/cosdfun.h \
    interpreter/cosrfun.h \
    interpreter/expfun.h \
    interpreter/expr.h \
    interpreter/factorialfun.h \
    interpreter/functionexpr.h \
    interpreter/functionmanager.h \
    interpreter/getrecordfun.h \
    interpreter/log10fun.h \
    interpreter/logfun.h \
    interpreter/multiplicativeexpr.h \
    interpreter/nonterminalexpr.h \
    interpreter/numberexpr.h \
    interpreter/powerfun.h \
    interpreter/primaryexpr.h \
    interpreter/recordfun.h \
    interpreter/rootfun.h \
    interpreter/saverecordfun.h \
    interpreter/sindfun.h \
    interpreter/sinrfun.h \
    interpreter/sumfun.h \
    interpreter/tandfun.h \
    interpreter/tanrfun.h \
    interpreter/terminalexpr.h \
    interpreter/token.h \
    interpreter/tokenanalyzer.h \
    interpreter/unaryexpr.h \
    mainwindow.h \
    questionedit.h \

FORMS    += \
    mainwindow.ui \
    helpdialog.ui

OTHER_FILES += \
    QtCalculator.pro.user \
    QtCalculator.pro \
    resource/help.html

RESOURCES += \
    resource.qrc



































































































































