#include "so_long.h"

int main(int argc, char **argv)
{
	t_data *game;

	if (argc == 2)
	{
		ber_control(argv[1]);
		//xpm_control();
		game = (t_data *)malloc(sizeof(t_data) * 1);
		read_map(game, argv[1]);

	}
	else
	{
		write(1, "Wrong usage\n./so_long <map path>\n", 33);
	}
	
	return (0);
}
