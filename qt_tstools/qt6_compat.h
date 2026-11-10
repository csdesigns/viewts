// Qt 6 dropped the QtCharts namespace and its QT_CHARTS_USE_NAMESPACE macro.
// Provide an empty definition so Qt 5-era sources keep compiling.
// This header is force-included before all user code (see viewTS.pro).
#ifndef QT6_COMPAT_H
#define QT6_COMPAT_H

// qmake preprocesses a dummy file (no Qt include paths) to build moc_predefs.h,
// so guard the include. In real compiles the Qt include path is present.
#if defined(__has_include)
#  if __has_include(<QtCore/qglobal.h>)
#    include <QtCore/qglobal.h>
#  endif
#endif

#ifdef QT_VERSION
#  if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#    define QT_CHARTS_USE_NAMESPACE
#  endif
#endif

#endif // QT6_COMPAT_H
