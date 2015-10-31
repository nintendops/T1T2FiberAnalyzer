#ifndef conf_Model_T1T2FiberAnalyzer_H
#define conf_Model_T1T2FiberAnalyzer_H

#include <QString>

class conf_Model_T1T2FiberAnalyzer {
  QString conf_DTIStatPath;
  QString conf_FiberProcessPath;
  QString conf_pypath;

public: 

  conf_Model_T1T2FiberAnalyzer();
  QString getconf_DTIStatPath();
  void setconf_DTIStatPath(QString a);

  QString getconf_FiberProcessPath();
  void setconf_FiberProcessPath(QString a);

  QString getconf_pypath();
  void setconf_pypath(QString a);

};

#endif
