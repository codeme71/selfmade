    // variant one
#include <gtk/gtk.h>

GtkWidget *create_table(void) {
    // Создаем таблицу с 5 строками и 5 столбцами
    GtkWidget *table = gtk_grid_new();

    // Добавляем 25 кнопок в таблицу
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            GtkWidget *button = gtk_button_new_with_label("Кнопка");
            gtk_grid_attach(GTK_GRID(table), button, i, j, 1, 1);
        }
    }

    return table;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Простая таблица");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *table = create_table();
    gtk_container_add(GTK_CONTAINER(window), table);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

    // variant two
     
     #include <gtk/gtk.h>

#define ROWS 10
#define COLS 5

GtkWidget *grid;
GtkWidget *entries[ROWS][COLS];

void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Spreadsheet");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Создание ячеек ввода
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            entries[i][j] = gtk_entry_new();
            gtk_grid_attach(GTK_GRID(grid), entries[i][j], j, i, 1, 1);
        }
    }

    // Кнопка для демонстрации
    GtkWidget *button = gtk_button_new_with_label("Print Values");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, ROWS, COLS, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

     // to ve continue
     
     
