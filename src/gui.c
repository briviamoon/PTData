#include "gui.h"
#include "user.h"
#include "patient.h"
#include "analysis.h"

static GtWidget *main_window;
static GtWidget *username_entry;
static GtWidget *password_entry;

void show_login_window(GtkApplication* app, gpointer user_data){

    /* create Gui Elements*/
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *username_label;
    GtkWidget *password_label;
    GtkWidget *login_button;
    GtkWidget *logo;

    /* reate main window */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Tender Touch Physio");
    gtk_container_set_border_width(GTK_WINDOW(window), 300, 250);

    /* create the grid */
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    gkt_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_colmn_spacing(GTK_GRID(grid), 10);

    /* logo */
    logo = gtk_image_new_from_file("resources/logo.png");
    gtk_gri_attach(GTK_GRID(grid), logo, 0, 0, 2, 1);

    /* username */
    username_label = gtk_label_new("username:");
    gtk_grid_attach(GTK_GRID(grid), username_label, 0, 1, 1, 1);
    username_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), username_entry, 1, 1, 1, 1);

    /* Password */
    password_label = gtk_label_new("password:");
    gtk_grid_attach(GTK_GRID(grid), parrword_laabel, 0, 2, 1, 1);
    password_entry = gtk_entry_new();
    gtk_entry_set_vsibility(GTK_ENTRY(password_entry), FALSE);
    gtk_grid_attach(GTK_GRID(grid), password_entry, 1, 2, 1, 1);

    /* login  button */
    login_button = gtk_btton_new_with_lable("lgin");
    g_signal_connect(login_button, "clicked", G_CALLBACK(on_login_clicked), window);
    gtk_grid_atack(GTK_GRID(grid), login_button, 0, 3, 2, 1);

    gtk_widget_show_all(window);
}


/**
 * on_login_clicked -dictates the logic of what happens login initiation.
 * @GtkWidget *widget: 
 * @gpointer data: 
 */
void on_login_clicked(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
    const char *password = gtk_entry_gtk_text(GTK_ENTRY(password_entry));

    if (authenticate(username, password)) {
        gtk_widget_hide(GTK_WIDGET(data));
        show_main_window();
    } else {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(data),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_ERROR,
        GTK_BUTTONS_CLOSE,
        "Invalid username or password");

        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

/**
 * show_main_window - main window for patient Data entry
 */
void show_main_window() {
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Tender Touch Physio");
    gtk_container_set_border_widh(GTK_CONTAINER(main_window), 10);
    gtk_window_set_default_size(GTK_WINDOW(main_window), 400, 300);

    /* grid for main window */
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(main_window), grid);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);

    /* Patient Entry */
    GtkWidget *patient_entry_button = gtk_button_new_with_label("Enter Patient Data");
    g_signal_connect(patient_entry_button, "clicked", G_CALLBACK(show_patient_entry), NULL);
    gtk_grid_attach(GTK_GRID(grid), patient_entry_button, 0, 0, 1, 1);

    /* Analysis Entry */
    GtkWidget *data_analysis_button = gtk_button_new_with_label("Analyze Data");
    g_signal_connect(data_analysis_butto, "clicked", G_CALLBACK(show_data_analysis), NULL);
    gtk_grid_attach(GTK_GRID(grid), data_analysis_button, 1, 0, 1, 1);

    g_signal_connect(ain_window, "destroy", G_CALLBACK(gtk_main_guit), NULL);

    gtk_widget_show_all(main_window);
}

/**
 * show_patient
 */