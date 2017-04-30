//
// mainwindow.hpp for Plazza in /home/gastal_r/rendu/Plazza/gui/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 14:35:28 2017 gastal_r
// Last update Sun Apr 30 16:58:01 2017 gastal_r
//

#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include      <QtGui>
#include      <vector>
#include      <QTextEdit>
#include "ui_mainwindow.h"
#include "IThread.hh"
#include "Plazza.hpp"

class Plazza;
class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(Plazza &, Orders &, char *);
  void     refreshList(const std::vector<NamedPipe::Data> &);

public slots:
  void	handleButton(void);
  void	handleButton2(void);

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
private:
  Plazza &	       _plazza;
  Orders &	       _order;
  char		       *_av;
};

#endif /* !_MAINWINDOW_HPP_ */
