#include "GameFunc.h"
#include "GamePhase.h"
#include "ChickDressroom.h"

// BG
static SDL_Texture* g_texture;
static SDL_Rect g_bg_rect;
static SDL_Rect g_bg_des_rect;

static SDL_Texture* title_texture_dr;
static SDL_Rect title_dr_rect;
static SDL_Rect title_dr_dest_rect;

static SDL_Texture* start_texture_dr;
static SDL_Rect start_rect;
static SDL_Rect start_dest_rect;

// Chick
static SDL_Texture* dress_chick_texture;
static SDL_Rect dress_chick_rect;
static SDL_Rect dress_chick_dest_rect;

static SDL_Texture* egg_texture;
static SDL_Rect egg_rect;
static SDL_Rect egg_dest_rect;

static SDL_Texture* angel_texture;
static SDL_Rect angel_rect;
static SDL_Rect angel_dest_rect;

static SDL_Texture* devil_texture;
static SDL_Rect devil_rect;
static SDL_Rect devil_dest_rect;

static SDL_Texture* sailor_texture;
static SDL_Rect sailor_rect;
static SDL_Rect sailor_dest_rect;

static SDL_Texture* egg_side_texture;
static SDL_Rect egg_side_rect;
static SDL_Rect egg_side_dest_rect;

static SDL_Texture* angel_side_texture;
static SDL_Rect angel_side_rect;
static SDL_Rect angel_side_dest_rect;

static SDL_Texture* devil_side_texture;
static SDL_Rect devil_side_rect;
static SDL_Rect devil_side_dest_rect;

static SDL_Texture* sailor_side_texture;
static SDL_Rect sailor_side_rect;
static SDL_Rect sailor_side_dest_rect;

int chick_dress = 0;


void Init_Dressroom()
{
	SDL_Surface* bg_surface = IMG_Load("../Resources/dressroom_bg.png");
	g_texture = SDL_CreateTextureFromSurface(g_renderer, bg_surface);
	SDL_FreeSurface(bg_surface);

	SDL_QueryTexture(g_texture, NULL, NULL, &g_bg_rect.w, &g_bg_rect.h);
	g_bg_des_rect.x = g_bg_rect.x = 0;
	g_bg_des_rect.y = g_bg_rect.y = 0;
	g_bg_des_rect.w = 800;
	g_bg_des_rect.h = 600;

	
	//
	SDL_Surface* title_surface = IMG_Load("../Resources/dressroom_title.png");
	title_texture_dr = SDL_CreateTextureFromSurface(g_renderer, title_surface);
	SDL_FreeSurface(title_surface);

	SDL_QueryTexture(title_texture_dr, NULL, NULL, &title_dr_rect.w, &title_dr_rect.h);
	title_dr_dest_rect.x = 280;
	title_dr_dest_rect.y = 50;
	title_dr_dest_rect.w = title_dr_rect.w / 1.5;
	title_dr_dest_rect.h = title_dr_rect.h / 1.5;

	//
	SDL_Surface* start_surface = IMG_Load("../Resources/start_button.png");
	start_texture_dr = SDL_CreateTextureFromSurface(g_renderer, start_surface);
	SDL_FreeSurface(start_surface);

	SDL_QueryTexture(start_texture_dr, NULL, NULL, &start_rect.w, &start_rect.h);
	start_dest_rect.x = 30;
	start_dest_rect.y = 480;
	start_dest_rect.w = start_rect.w / 10;
	start_dest_rect.h = start_rect.h / 10;

	//
	SDL_Surface* ari_surface = IMG_Load("../Resources/dressroom_ari.png");
	dress_chick_texture = SDL_CreateTextureFromSurface(g_renderer, ari_surface);
	SDL_FreeSurface(ari_surface);

	SDL_QueryTexture(dress_chick_texture, NULL, NULL, &dress_chick_rect.w, &dress_chick_rect.h);
	dress_chick_dest_rect.x = 100;
	dress_chick_dest_rect.y = 290;
	dress_chick_dest_rect.w = dress_chick_rect.w / 18;
	dress_chick_dest_rect.h = dress_chick_rect.h / 18;

	// Egg
	SDL_Surface* egg_surface = IMG_Load("../Resources/Egg.png");
	egg_texture = SDL_CreateTextureFromSurface(g_renderer, egg_surface);
	SDL_FreeSurface(egg_surface);

	SDL_QueryTexture(egg_texture, NULL, NULL, &egg_rect.w, &egg_rect.h);
	egg_dest_rect.x = 370;
	egg_dest_rect.y = 220;
	egg_dest_rect.w = egg_rect.w / 7;
	egg_dest_rect.h = egg_rect.h / 7;

	// Angel
	SDL_Surface* angel_surface = IMG_Load("../Resources/Angel.png");
	angel_texture = SDL_CreateTextureFromSurface(g_renderer, angel_surface);
	SDL_FreeSurface(angel_surface);

	SDL_QueryTexture(angel_texture, NULL, NULL, &angel_rect.w, &angel_rect.h);
	angel_dest_rect.x = 380;
	angel_dest_rect.y = 370;
	angel_dest_rect.w = angel_rect.w / 20;
	angel_dest_rect.h = angel_rect.h / 20;

	// Devil
	SDL_Surface* devil_surface = IMG_Load("../Resources/Devil.png");
	devil_texture = SDL_CreateTextureFromSurface(g_renderer, devil_surface);
	SDL_FreeSurface(devil_surface);

	SDL_QueryTexture(devil_texture, NULL, NULL, &devil_rect.w, &devil_rect.h);
	devil_dest_rect.x = 580;
	devil_dest_rect.y = 370;
	devil_dest_rect.w = devil_rect.w / 10;
	devil_dest_rect.h = devil_rect.h / 10;

	// Sailor Moon
	SDL_Surface* sailor_surface = IMG_Load("../Resources/SailorMoon.png");
	sailor_texture = SDL_CreateTextureFromSurface(g_renderer, sailor_surface);
	SDL_FreeSurface(sailor_surface);

	SDL_QueryTexture(sailor_texture, NULL, NULL, &sailor_rect.w, &sailor_rect.h);
	sailor_dest_rect.x = 590;
	sailor_dest_rect.y = 220;
	sailor_dest_rect.w = sailor_rect.w / 11;
	sailor_dest_rect.h = sailor_rect.h / 11;

	// Egg Side
	SDL_Surface* egg_side_surface = IMG_Load("../Resources/egg_ari_sheet.png");
	egg_side_texture = SDL_CreateTextureFromSurface(g_renderer, egg_side_surface);
	SDL_FreeSurface(egg_side_surface);

	egg_side_rect = { 88, 90, 300, 300 };
	egg_side_dest_rect.x = 100;
	egg_side_dest_rect.y = 290;
	egg_side_dest_rect.w = egg_side_rect.w / 3;
	egg_side_dest_rect.h = egg_side_rect.h / 3;

	// Angel Side
	SDL_Surface* angel_side_surface = IMG_Load("../Resources/angel_ari_sheet.png");
	angel_side_texture = SDL_CreateTextureFromSurface(g_renderer, angel_side_surface);
	SDL_FreeSurface(angel_side_surface);

	angel_side_rect = { 88, 28, 301, 351 };
	angel_side_dest_rect.x = 100;
	angel_side_dest_rect.y = 290;
	angel_side_dest_rect.w = angel_side_rect.w / 3;
	angel_side_dest_rect.h = angel_side_rect.h / 3;

	// Devil Side
	SDL_Surface* devil_side_surface = IMG_Load("../Resources/devil_ari_sheet.png");
	devil_side_texture = SDL_CreateTextureFromSurface(g_renderer, devil_side_surface);
	SDL_FreeSurface(devil_side_surface);

	devil_side_rect = { 89, 72, 300, 318 };
	devil_side_dest_rect.x = 100;
	devil_side_dest_rect.y = 290;
	devil_side_dest_rect.w = devil_side_rect.w / 3;
	devil_side_dest_rect.h = devil_side_rect.h / 3;

	// Sailor Moon Side
	SDL_Surface* sailor_side_surface = IMG_Load("../Resources/sailormoon_ari_sheet.png");
	sailor_side_texture = SDL_CreateTextureFromSurface(g_renderer, sailor_side_surface);
	SDL_FreeSurface(sailor_side_surface);

	sailor_side_rect = { 89, 98, 302, 283 };
	sailor_side_dest_rect.x = 100;
	sailor_side_dest_rect.y = 290;
	sailor_side_dest_rect.w = sailor_side_rect.w / 3;
	sailor_side_dest_rect.h = sailor_side_rect.h / 3;


}

void HandleEvents_Dressroom()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;

			break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;
				
				// Start Button
				if (mouse_x > start_dest_rect.x &&
					mouse_y > start_dest_rect.y &&
					mouse_x < start_dest_rect.x + start_dest_rect.w &&
					mouse_y < start_dest_rect.y + start_dest_rect.h)
				{
					Init_Infinite();
					startTime = SDL_GetTicks();
					g_current_game_phase = PHASE_INFINITE;
				}

				// Egg
				if (mouse_x > egg_dest_rect.x &&
					mouse_y > egg_dest_rect.y &&
					mouse_x < egg_dest_rect.x + egg_dest_rect.w &&
					mouse_y < egg_dest_rect.y + egg_dest_rect.h)
				{
					std::cout << "EGG" << std::endl;
					chick_dress = 1;
					SDL_DestroyTexture(dress_chick_texture);
					
				}

				// Angel
				if (mouse_x > angel_dest_rect.x &&
					mouse_y > angel_dest_rect.y &&
					mouse_x < angel_dest_rect.x + angel_dest_rect.w &&
					mouse_y < angel_dest_rect.y + angel_dest_rect.h)
				{
					std::cout << "ANGEL" << std::endl;
					chick_dress = 2;
					SDL_DestroyTexture(dress_chick_texture);
				}


				// Devil
				if (mouse_x > devil_dest_rect.x &&
					mouse_y > devil_dest_rect.y &&
					mouse_x < devil_dest_rect.x + devil_dest_rect.w &&
					mouse_y < devil_dest_rect.y + devil_dest_rect.h)
				{
					std::cout << "DEVIL" << std::endl;
					chick_dress = 3;
					SDL_DestroyTexture(dress_chick_texture);
				}

				// Sailor Moon
				if (mouse_x > sailor_dest_rect.x &&
					mouse_y > sailor_dest_rect.y &&
					mouse_x < sailor_dest_rect.x + sailor_dest_rect.w &&
					mouse_y < sailor_dest_rect.y + sailor_dest_rect.h)
				{
					std::cout << "SAILOR MOON" << std::endl;
					chick_dress = 4;
					SDL_DestroyTexture(dress_chick_texture);
				}
			}
		}
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				g_flag_running = false;
			}
		}
	}
}

void Update_Dressroom()
{

}

void Render_Dressroom()
{
	SDL_RenderCopy(g_renderer, g_texture, &g_bg_rect, &g_bg_des_rect);

	SDL_RenderCopy(g_renderer, title_texture_dr, &title_dr_rect, &title_dr_dest_rect);

	SDL_RenderCopy(g_renderer, start_texture_dr, &start_rect, &start_dest_rect);

	SDL_RenderCopy(g_renderer, dress_chick_texture, &dress_chick_rect, &dress_chick_dest_rect);

	SDL_RenderCopy(g_renderer, egg_texture, &egg_rect, &egg_dest_rect);

	SDL_RenderCopy(g_renderer, angel_texture, &angel_rect, &angel_dest_rect);

	SDL_RenderCopy(g_renderer, devil_texture, &devil_rect, &devil_dest_rect);

	SDL_RenderCopy(g_renderer, sailor_texture, &sailor_rect, &sailor_dest_rect);
	
	if (chick_dress == 1)
		SDL_RenderCopy(g_renderer, egg_side_texture, &egg_side_rect, &egg_side_dest_rect);
	
	if (chick_dress == 2)
		SDL_RenderCopy(g_renderer, angel_side_texture, &angel_side_rect, &angel_side_dest_rect);

	if (chick_dress == 3)
		SDL_RenderCopy(g_renderer, devil_side_texture, &devil_side_rect, &devil_side_dest_rect);

	if (chick_dress == 4)
		SDL_RenderCopy(g_renderer, sailor_side_texture, &sailor_side_rect, &sailor_side_dest_rect);

	SDL_RenderPresent(g_renderer);
}	


void Clear_Dressroom()
{
	SDL_DestroyTexture(g_texture);
	SDL_DestroyTexture(title_texture_dr);
	SDL_DestroyTexture(start_texture_dr);
	SDL_DestroyTexture(dress_chick_texture);
	SDL_DestroyTexture(egg_texture);
	SDL_DestroyTexture(angel_texture);
	SDL_DestroyTexture(devil_texture);
	SDL_DestroyTexture(sailor_texture);
	SDL_DestroyTexture(egg_side_texture);
}

