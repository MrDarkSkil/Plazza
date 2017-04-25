//
// mainwindow.hpp for Plazza in /home/gastal_r/rendu/Plazza/gui/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 14:35:28 2017 gastal_r
// Last update Tue Apr 25 12:30:56 2017 gastal_r
//

#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include "ui_mainwindow.h"


class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

    void     listView();
    
protected:
    void closeEvent(QCloseEvent *event) override;

  private slots:
};

#endif /* !_MAINWINDOW_HPP_ */
