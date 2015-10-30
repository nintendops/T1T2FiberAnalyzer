#ifndef para_Model_T1T2FiberAnalyzer_H
#define para_Model_T1T2FiberAnalyzer_H

#include <QString>
#include <map>

class para_Model_T1T2FiberAnalyzer {
  QString para_DTIComboPath;
  QString para_DTIComboSID;
  QString para_T12ComboPath;
  QString para_T12ComboSID;
  QString para_DTIFiber_Path;
  QString para_DTIdefInputText;
  QString para_T12MapInputText;
  std::map<QString,bool> para_CSVMatchTable;
  std::map<QString,bool> para_Fiber_Tracts_Table;

public: 

  QString getpara_DTIComboPath();
  void setpara_DTIComboPath(QString a);

  QString getpara_DTIComboSID();
  void setpara_DTIComboSID(QString a);

  QString getpara_T12ComboPath();
  void setpara_T12ComboPath(QString a);

  QString getpara_T12ComboSID();
  void setpara_T12ComboSID(QString a);

  QString getpara_DTIFiber_Path();
  void setpara_DTIFiber_Path(QString a);

  QString getpara_DTIdefInputText();
  void setpara_DTIdefInputText(QString a);

  QString getpara_T12MapInputText();
  void setpara_T12MapInputText(QString a);

  std::map<QString,bool> getpara_CSVMatchTable();
  void setpara_CSVMatchTable(std::map<QString,bool> a);

  std::map<QString,bool> getpara_Fiber_Tracts_Table();
  void setpara_Fiber_Tracts_Table(std::map<QString,bool> a);

};

#endif
