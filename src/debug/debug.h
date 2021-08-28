//
// Created by Caleb Huck on 8/28/21.
//

#ifndef CHECKERSGUI_DEBUG_H
#define CHECKERSGUI_DEBUG_H

#include <QtCore/qstring.h>

void DebugMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif //CHECKERSGUI_DEBUG_H
