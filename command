gcc -L minilibx_opengl_20191021 -I minilibx_opengl_20191021 -lmlx -framework OpenGL -framework appkit mlx_start.c lodev.c testing_utils.c move_rotate.c rotate.c put_tex.c get_sprites.c get_sprite_distance.c sort_sprites.c put_sprites.c -L. -lft -g3 init_tex.c -fsanitize=address

avec truc dans autre dir: gcc -L minilibx_opengl_20191021 -I minilibx_opengl_20191021 -lmlx -framework OpenGL -framework appkit mlx_start.c lodev.c testing_utils.c move_rotate.c rotate.c put_tex.c get_sprites.c get_sprite_distance.c sort_sprites.c put_sprites.c -Llibft -lft -Llibft -lftprintf -g3 init_tex.c -fsanitize=address

gcc -Llibft -lft -Llibft -lftprintf parse_master.c
