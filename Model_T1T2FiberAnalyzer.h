#ifndef Model_T1T2FiberAnalyzer_H
#define Model_T1T2FiberAnalyzer_H

#include <QString>
#include <map>

class Model_T1T2FiberAnalyzer {
  QString DTIComboPath;
  QString DTIComboSID;
  QString T12ComboPath;
  QString T12ComboSID;
  QString DTIFiber_Path;
  QString DTIStatPath;
  QString DTIdefInputText;
  QString FiberProcessPath;
  QString T12MapInputText;
  QString pyPath;
  std::map<QString,bool> CSVMatchTable;
  std::map<QString,bool> Fiber_Tracts_Table;

public: 

  QString getDTIComboPath();
  void setDTIComboPath(QString a);

  QString getDTIComboSID();
  void setDTIComboSID(QString a);

  QString getT12ComboPath();
  void setT12ComboPath(QString a);

  QString getT12ComboSID();
  void setT12ComboSID(QString a);

  QString getDTIFiber_Path();
  void setDTIFiber_Path(QString a);

  QString getDTIStatPath();
  void setDTIStatPath(QString a);

  QString getDTIdefInputText();
  void setDTIdefInputText(QString a);

  QString getFiberProcessPath();
  void setFiberProcessPath(QString a);

  QString getT12MapInputText();
  void setT12MapInputText(QString a);

  QString getpyPath();
  void setpyPath(QString a);

  std::map<QString,bool> getCSVMatchTable();
  void setCSVMatchTable(std::map<QString,bool> a);

  std::map<QString,bool> getFiber_Tracts_Table();
  void setFiber_Tracts_Table(std::map<QString,bool> a);

};

#endif
