#ifndef para_Model_T1T2FiberAnalyzer_H
#define para_Model_T1T2FiberAnalyzer_H

#include <QString>
#include <vector>
#include <stdexcept>

class para_Model_T1T2FiberAnalyzer {
  QString para_DTIComboPath;
  QString para_DTIComboSID;
  QString para_T12ComboPath;
  QString para_T12ComboSID;
  QString para_DTIFiber_Path;
  QString para_DTIdefInputText;
  QString para_T12MapInputText;
  std::vector<std::vector<QString> > para_CSVMatchTable;
  std::vector<std::vector<QString> > para_Fiber_Tracts_Table;

public: 

  para_Model_T1T2FiberAnalyzer();
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

  std::vector<std::vector<QString> > getpara_CSVMatchTable();
  void setpara_CSVMatchTable(std::vector<std::vector<QString> > a);

  std::vector<std::vector<QString> > getpara_Fiber_Tracts_Table();
  void setpara_Fiber_Tracts_Table(std::vector<std::vector<QString> > a);

};

#endif
