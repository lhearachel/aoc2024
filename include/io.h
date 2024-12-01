#ifndef AOC2024_IO_H
#define AOC2024_IO_H

typedef void (*load_callback)(const char *line, const int i, void *cb_data);

void load_data(const char *inp, void *cb_data, load_callback cb);

#endif // AOC2024_IO_H
