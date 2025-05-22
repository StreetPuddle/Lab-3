#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>//Our primitive header file
#include <allegro5/allegro_native_dialog.h> 

void draw_filled_triforce(int pos_x, int pos_y);

int main(void) {
	ALLEGRO_DISPLAY* Screen = NULL;

	if (!al_init()) {
		al_show_native_message_box(NULL, "Error!", "Allegro has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	int width = 800, height = 600;
	Screen = al_create_display(width, height);
	if (Screen == NULL) {
		al_show_native_message_box(Screen, "Error!", "Failed to create the display.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	bool done = false;
	int pos_x = width / 2;
	int pos_y = height / 2;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT ev;

	al_init_primitives_addon();
	al_install_keyboard();
	if (!al_install_keyboard()) { ///setup the keyboard 
		al_show_native_message_box(NULL, "Error!", "Failed to install keyboard.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	event_queue = al_create_event_queue();
	event_queue = al_create_event_queue();
	if (event_queue == NULL) {
		al_show_native_message_box(Screen, "Error!", "Failed to create the event queue.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done) {

		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP://up
				pos_y -= 10;
				break;
			case ALLEGRO_KEY_DOWN://down
				pos_y += 10;
				break;
			case ALLEGRO_KEY_RIGHT://right
				pos_x += 10;
				break;
			case ALLEGRO_KEY_LEFT://left
				pos_x -= 10;
				break;
			case ALLEGRO_KEY_U://up left
				pos_x -= 10;
				pos_y -= 10;
				break;
			case ALLEGRO_KEY_D://down right
				pos_x += 10;
				pos_y += 10;
				break;
			case ALLEGRO_KEY_R://up right
				pos_x += 10;
				pos_y -= 10;
				break;
			case ALLEGRO_KEY_L://down left
				pos_x -= 10;
				pos_y += 10;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				done = true;
			}
		}

		draw_filled_triforce(pos_x, pos_y);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(Screen);//destroy our display object
	system("pause");
	return 0;
}

//draws a golden triforce aka three triangles in a formation
//@param pos_x x cordinate
//@param pos_y y cordinate
void draw_filled_triforce(int pos_x, int pos_y) {
	al_draw_filled_triangle(pos_x, pos_y, pos_x + 30, pos_y - 30, pos_x + 60, pos_y, al_map_rgb(255, 220, 0));
	al_draw_filled_triangle(pos_x - 30, pos_y + 30, pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 220, 0));
	al_draw_filled_triangle(pos_x + 29, pos_y + 30, pos_x + 90, pos_y + 30, pos_x + 60, pos_y, al_map_rgb(255, 220, 0));
}