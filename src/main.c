#include "common.h"
#include "database.h"
#include "gui.h"

int main(int argc, char **argv) {
    if (!init_database()) {
        fprintf(stderr, "Failed ti Initialize database\n");
        return(1);
    }

    GitApplication *app;
    int status;

    app = gtk_application_new("com.TenderTouch.PhysioClinic", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(show_login_window), NULL);
    status = g_application_run
    g_object_unref(app);

    close_database();

    return(status);

}