/*
** gamma_correction.c for raytracer in /home/collin_b//raytracer-2017-bridou_n
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Sat Jun  8 22:11:45 2013 jonathan collinet
** Last update Sun Jun  9 12:12:13 2013 nicolas bridoux
*/

#include "raytracer.h"

t_color		gamma_correction(t_rt *scene, t_color color)
{
  color.r = 255 * pow((color.r / 255), scene->gamma);
  color.g = 255 * pow((color.g / 255), scene->gamma);
  color.b = 255 * pow((color.b / 255), scene->gamma);
  return (color);
}
