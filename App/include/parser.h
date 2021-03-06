#ifndef PARSER_H
#define PARSER_H
#include "network.h"

network parse_network_cfg(char *filename);
void save_network(network net, char *filename);
void save_weights(network net, char *filename);
void save_weights_upto(network net, char *filename, int cutoff);
void save_weights_double(network net, char *filename);
void load_weights(network *net, char *filename);
void load_weights_upto(network *net, char *filename, int start, int cutoff);

void load_weights_from_float(layer *l, float* w, int n); 

#endif
