//
// mainwindow.hpp for Plazza in /home/gastal_r/rendu/Plazza/gui/includes/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 14:35:28 2017 gastal_r
// Last update Mon Apr 24 15:41:24 2017 gastal_r
//

#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include "ui_mainwindow.h"


class MainWindow : public QWidget, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
/*
public slots:
    void getPath();
    void doSomething();
    void clear();
    void about(); */
};

#endif /* !_MAINWINDOW_HPP_ */
