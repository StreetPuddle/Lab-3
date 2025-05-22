#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>//Our primitive header file
#include <allegro5/allegro_native_dialog.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//draws a golden triforce aka three triangles in a formation
//@param pos_x x cordinate
//@param pos_y y cordinate
void draw_filled_triforce(int pos_x, int pos_y);

int main(void) {

	al_init_primitives_addon();
	al_init_font_addon;
	al_init_ttf_addon;

	int width = 800, height = 600;
	int pos_x = width / 2;
	int pos_y = height / 2;
	bool done = false, draw = false;

	ALLEGRO_DISPLAY *Screen = NULL;
	Screen = al_create_display(width, height);

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	event_queue = al_create_event_queue();

	ALLEGRO_FONT *font24 = al_load_font("AppleGaramond.ttf", 24, 0);

	al_register_event_source(event_queue, al_get_display_event_source(Screen));
	al_clear_to_color;

	if (!al_install_mouse()) {
		al_show_native_message_box(Screen, "Error!", "Failed to initialize the mouse\n", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (!al_init()) {
		al_show_native_message_box(NULL, "Error!", "Allegro has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if (Screen == NULL) {
		al_show_native_message_box(Screen, "Error!", "Failed to create the display.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	event_queue = al_create_event_queue();
	if (event_queue == NULL) {
		al_show_native_message_box(Screen, "Error!", "Failed to create the event queue.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_register_event_source(event_queue, al_get_mouse_event_source());

	while (!done) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		} else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 1) {
				draw = true;
				pos_x = ev.mouse.x;
				pos_y = ev.mouse.y;
			}
		}

		if (draw) {
			if (pos_x <= 200 && pos_x >= 0 && pos_y >= 0 && pos_y <= 200) {
				draw_filled_triforce(0, 0, al_map_rgb(150, 150, 150));
				draw_filled_triforce(400, 400, al_map_rgb(0, 0, 0));
				al_draw_textf(font24, al_map_rgb(255, 255, 255), pos_x, pos_y, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", pos_x, pos_y);
				al_flip_display();
			} else if (pos_x >= 400 && pos_x <= 640 && pos_y >= 400 && pos_y <= 480) {
				draw_filled_triforce(400, 400, al_map_rgb(150, 0, 150));
				draw_filled_triforce(0, 0, al_map_rgb(0, 0, 0));
				al_draw_textf(font24, al_map_rgb(255, 255, 255), pos_x, pos_y, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", pos_x, pos_y);
				al_flip_display();
			} else {
				draw_filled_triforce(0, 0, al_map_rgb(0, 0, 0));
				draw_filled_triforce(400, 400, al_map_rgb(0, 0, 0));
				al_draw_textf(font24, al_map_rgb(255, 255, 255), pos_x, pos_y, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", pos_x, pos_y);
				al_flip_display();
			}
		}

		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(Screen);
	al_destroy_font(font24);
	system("pause");
	return 0;
}

void draw_filled_triforce(int pos_x, int pos_y, ALLEGRO_COLOR color) {
	al_draw_filled_triangle(pos_x, pos_y, pos_x + 30, pos_y - 30, pos_x + 60, pos_y, color);
	al_draw_filled_triangle(pos_x - 30, pos_y + 30, pos_x, pos_y, pos_x + 30, pos_y + 30, color);
	al_draw_filled_triangle(pos_x + 29, pos_y + 30, pos_x + 90, pos_y + 30, pos_x + 60, pos_y, color);
}