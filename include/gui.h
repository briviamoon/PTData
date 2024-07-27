#ifndef GUI_H
#define GUI_H

#include "common.h"
#include "user.h"
#include "patient.h"
#include "analysis.h"

void show_login_window(GtkApplication* app, gpointer user_data);
void on_login_clicked(GtkWidget *widget, gpointer data);
void show_main_window();
void show_patient_entry();
void add_form_field(GtkWidget *grid, const char *label_text, int row);
void on_patient_submit(GtkWidget *widget, gpointer data);
void show_data_analysis();

#endif
