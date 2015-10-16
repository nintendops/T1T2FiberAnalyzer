#ifndef Model_T1T2FiberAnalyzer_H
#define Model_T1T2FiberAnalyzer_H

#include <QString>

class Model_T1T2FiberAnalyzer {
  QString DTIComboPath;
  QString DTIComboSID;
  QString T12ComboPath;
  QString T12ComboSID;
  QString DTIFiber_Path;
  QString DTIdefInputText;
  QString T12MapInputText;
  QString lineEdit_2;
  QString lineEdit_3;
  QString pyPath;

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

  QString getDTIdefInputText();
  void setDTIdefInputText(QString a);

  QString getT12MapInputText();
  void setT12MapInputText(QString a);

  QString getlineEdit_2();
  void setlineEdit_2(QString a);

  QString getlineEdit_3();
  void setlineEdit_3(QString a);

  QString getpyPath();
  void setpyPath(QString a);

};

#endif
