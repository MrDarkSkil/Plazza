//
// mainwindow.hpp for Plazza in /home/gastal_r/rendu/Plazza/gui/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 14:35:28 2017 gastal_r
// Last update Wed Apr 26 01:54:20 2017 gastal_r
//

#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include      <QtGui>
#include      <vector>
#include "ui_mainwindow.h"
#include "NamedPipe.hpp"
#include "IThread.hh"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

    void     refreshList(const std::vector<NamedPipe::Data> &);

protected:
    void closeEvent(QCloseEvent *event) override;

  private slots:
  private:
};

#endif /* !_MAINWINDOW_HPP_ */
