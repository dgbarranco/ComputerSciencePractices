#ifndef WINDOW_H
#define WINDOW_H

typedef struct
{
    int width;
    int height;
    const char *title;
} Window;

int Window_Create(Window *window);
void Window_Update(void);
void Window_Destroy(void);

#endif
