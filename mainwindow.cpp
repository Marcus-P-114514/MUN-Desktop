#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"

//预定义字段 - 仅供读取主题
QString theme_pref;
QString primary_current = "";
QString background_current = "";
QString toolbar_current;
QString text_color_current = "";
QString primary_current_16 = "";
QString toolbar_shade_current = "";
QString ui_stylesheet_general = "";
QString ui_btn_default = "";
QString ui_btn_frameless = "";
QString ui_btn_suggested = "";
QString ui_sidebar_selected = "";
QString ui_sidebar_released = "";
QString ui_lineedit = "";
QString ui_combobox = "";
QString ui_radio_selected = "";
QString ui_radio_released = "";
QString ui_textedit;
QString ui_quickinsert;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //预设的主题
    //浅色
    QString primary_light = "#E7BF9F";
    QString background_light = "#F6F0E5";
    QString text_color_selected_light = "#FFFFFF";
    QString toolbar_light="#E7BF9F";

    //深色
    QString primary_dark = "#E7BF9F";
    QString background_dark = "rgb(69,69,69)";
    QString text_color_selected_dark = "#FFFFFF";
    QString toolbar_dark="#E7BF9F";

    //黑色
    QString primary_black = "#E7BF9F";
    QString background_black = "rgb(0,0,0)";
    QString text_color_selected_black = "#FFFFFF";
    QString toolbar_black="#rgb(0,0,0)";

    //读取主题
    QSettings *config_theme = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    //QString theme_pref_read = config_theme -> value ( "theme/name").toString();
    //theme_pref_read = theme_pref;
    //qDebug()<<theme_pref_read;

    QSettings *config_theme_n = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    theme_pref = config_theme -> value ( "theme/name").toString();
    delete config_theme_n;


    //应用预设
    if (theme_pref == "light"){
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }
    else if (theme_pref == "dark"){
        primary_current = primary_dark;
        background_current = background_dark;
        text_color_current = text_color_selected_dark;
        toolbar_current = toolbar_dark;
    }
    else if (theme_pref == "black"){
        primary_current = primary_black;
        background_current = background_black;
        text_color_current = text_color_selected_black;
        toolbar_current = toolbar_black;
    }
    else{
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        //toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }

    delete config_theme;

    //生成样式表
    //primary_current_16 = converRGB16HexStr(primary_current);
    //ui_stylesheet_general = "QMenu::item:selected{background-color:" + background_current  + ";color:" + primary_current + ";}QMenu::item{background-color:" + primary_current + ";color:" + text_color_current + ";}QMenu::item:disabled{background-color:" + primary_current + ";color: #ddd" + "}QMenu{background-color:" +  primary_current + ";}" + "QWidget{background-color:" +  background_current + "; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color:" + primary_current + " ;}" + "QMenuBar{background-color:" + primary_current + "; color: " + text_color_current +";}";
    ui_stylesheet_general = "QMenu::item:selected{background-color:" + background_current  + ";color:" + primary_current + ";}QMenu::item{background-color:" + primary_current + ";color:" + text_color_current + ";}QMenu::item:disabled{background-color:" + primary_current + ";color: #ddd" + "}QMenu{background-color:" +  toolbar_current + "; color: " + primary_current + ";}" + "QWidget{background-color:" +  background_current + "; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color:" + primary_current + " ;}" + "QMenuBar{background-color:" + toolbar_current + "; color: " + text_color_current +";}";
    ui_btn_frameless = "QPushButton{border-radius: 5px; background-color: " + background_current + "; color:" + primary_current + ";border: 6px;}";
    ui_btn_suggested = "QPushButton{border-radius: 5px; background-color: " + primary_current + "; color:" + text_color_current + ";border: 6px;}";
    ui_radio_selected = ui_btn_suggested;
    ui_radio_released = ui_btn_frameless;
    ui_sidebar_selected = "QPushButton{text-align : left;padding: 7px;}" + ui_btn_suggested;
    ui_sidebar_released = "QPushButton{text-align : left;padding: 7px;}" + ui_btn_frameless;
    ui_lineedit = "padding: 3px; border: 2px solid " + primary_current + "; border-radius: 5px;";
    ui_combobox = "QComboBox::down-arrow{border: 2px solid "+ primary_current + "; border-radius: 5px; background-color: "+ primary_current + "; color:" + text_color_current + "; min-width: 10px;} QComboBox{border-radius: 5px; background-color: "+ primary_current + "; color:" + text_color_current + ";}";
    ui_textedit = ui_lineedit;
    ui_quickinsert = "background: " + primary_current + "; color: " + text_color_current + ";";

    //初始化界面
    this->setStyleSheet(ui_stylesheet_general);


    ui->setupUi(this);
    ui->switch_general_speaker_list->setStyleSheet("QPushButton{border-radius: 5px; background-color: #E7BF9F; color:#FFFFFF;border: 6px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

