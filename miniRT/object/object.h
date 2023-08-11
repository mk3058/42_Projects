/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:29:41 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 13:01:00 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "coordinate.h"

typedef enum e_object_type {
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

typedef struct s_object {
	t_object_type	type;
	void			*obj;
	struct s_object	*next;
}	t_object;

typedef struct s_ambient {
	double	brightness;
	t_color	color;
}	t_ambient;

typedef struct s_light {
	t_point	origin;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_camera {
	t_point	origin;
	t_vec	d_vec;
	double	fov;
}	t_camera;

typedef struct s_sphere {
	t_point	origin;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane {
	t_point	origin;
	t_vec	n_vec;
	t_color	color;
}	t_plane;

typedef struct s_cylinder {
	t_point	center;
	t_vec	axis;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

t_object	object(t_object **head, t_object_type type, void *object);
t_ambient	ambient(double brightness, t_color color);
t_light		light(t_point origin, double brightness, t_color color);
t_camera	camera(t_point origin, t_vec d_vec, double fov);
t_sphere	sphere(t_point origin, double radius, t_color color);
t_plane		plane(t_point origin, t_vec n_vec, t_color color);
t_cylinder	cylinder(t_point origin, t_vec axis, double radius, \
						double height, t_color color);
void		o_add(t_object **head, t_object *new);
t_object	*o_last(t_object *head);

#endif