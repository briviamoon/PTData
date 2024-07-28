#include "../include/common.h"
#include "../include/database.h"
#include "../include/gui.h"

int main(int argc, char **argv) {
    //if (!init_database()) {
    //    fprintf(stderr, "Failed ti Initialize database\n");
    //    return(1);
    //}

    GtkApplication *app;
    int status;

    app = gtk_application_new("com.TenderTouch.PhysioClinic", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(show_login_window), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    close_database();

    return(status);

}
