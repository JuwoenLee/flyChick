#include "GameFunc.h"
#include "GamePhase.h"
#include "SDL_mixer.h"

static SDL_Texture* g_texture_intro; // the SDL_Texture 
static SDL_Rect g_source_rectangle_intro; // the rectangle for source image
static SDL_Rect g_destination_rectangle_intro; // for destination

static SDL_Texture* title_texture_intro;
static SDL_Rect title_rect;
static SDL_Rect title_destination_rect;

static SDL_Texture* story_texture_intro;
static SDL_Rect story_rect;
static SDL_Rect story_destination_rect;

static SDL_Texture* infinity_texture_intro;
static SDL_Rect infinity_rect;
static SDL_Rect infinity_destination_rect;

static SDL_Texture* sound_texture_intro;
static SDL_Rect sound_rect;
static SDL_Rect sound_destination_rect;

static SDL_Texture* sound_low_button;
static SDL_Rect sound_low_rect;
static SDL_Rect sound_low_destination_rect;

static SDL_Texture* sound_middle_button;
static SDL_Rect sound_middle_rect;
static SDL_Rect sound_middle_destination_rect;

static SDL_Texture* sound_loud_button;
static SDL_Rect sound_loud_rect;
static SDL_Rect sound_loud_destination_rect;

// 볼륨버튼 추가

Mix_Music* g_intro_music;

POINT ptMouse;



void Init_Intro()
{
	SDL_Surface* intro_bg_surface = IMG_Load("../Resources/intro_bg.png");
	g_texture_intro = SDL_CreateTextureFromSurface(g_renderer, intro_bg_surface);
	SDL_FreeSurface(intro_bg_surface);

	SDL_QueryTexture(g_texture_intro, NULL, NULL, &g_source_rectangle_intro.w, &g_source_rectangle_intro.h);
	g_destination_rectangle_intro.x = g_source_rectangle_intro.x = 0;
	g_destination_rectangle_intro.y = g_source_rectangle_intro.y = 0;
	g_destination_rectangle_intro.w = 800;
	g_destination_rectangle_intro.h = 600;

	SDL_Surface* title_surface = IMG_Load("../Resources/title.png");
	title_texture_intro = SDL_CreateTextureFromSurface(g_renderer, title_surface);
	SDL_FreeSurface(title_surface);

	SDL_QueryTexture(title_texture_intro, NULL, NULL, &title_rect.w, &title_rect.h);
	title_destination_rect.x = 30;
	title_destination_rect.y = 100;
	title_destination_rect.w = title_rect.w / 1.2;
	title_destination_rect.h = title_rect.h / 1.2;

	SDL_Surface* infinity_surface = IMG_Load("../Resources/infinitymode_button.png");
	infinity_texture_intro = SDL_CreateTextureFromSurface(g_renderer, infinity_surface);
	SDL_FreeSurface(infinity_surface);

	SDL_QueryTexture(infinity_texture_intro, NULL, NULL, &infinity_rect.w, &infinity_rect.h);
	infinity_destination_rect.x = 150;
	infinity_destination_rect.y = 350;
	infinity_destination_rect.w = infinity_rect.w / 8;
	infinity_destination_rect.h = infinity_rect.h / 8;

	SDL_Surface* story_surface = IMG_Load("../Resources/storymode_button.png");
	story_texture_intro = SDL_CreateTextureFromSurface(g_renderer, story_surface);
	SDL_FreeSurface(story_surface);

	SDL_QueryTexture(story_texture_intro, NULL, NULL, &story_rect.w, &story_rect.h);
	story_destination_rect.x = 490;
	story_destination_rect.y = 350;
	story_destination_rect.w = story_rect.w / 8;
	story_destination_rect.h = story_rect.h / 8;

	// sound select

	SDL_Surface* sound_surface = IMG_Load("../Resources/sound1.png");
	sound_texture_intro = SDL_CreateTextureFromSurface(g_renderer, sound_surface);
	SDL_FreeSurface(sound_surface);

	SDL_QueryTexture(sound_texture_intro, NULL, NULL, &sound_rect.w, &sound_rect.h);
	sound_destination_rect.x = 510;
	sound_destination_rect.y = 520;
	sound_destination_rect.w = sound_rect.w / 30;
	sound_destination_rect.h = sound_rect.h / 30;

	SDL_Surface* sound_low_surface = IMG_Load("../Resources/low.png");
	sound_low_button = SDL_CreateTextureFromSurface(g_renderer, sound_low_surface);
	SDL_FreeSurface(sound_low_surface);

	SDL_QueryTexture(sound_low_button, NULL, NULL, &sound_low_rect.w, &sound_low_rect.h);
	sound_low_destination_rect.x = 580;
	sound_low_destination_rect.y = 520;
	sound_low_destination_rect.w = sound_low_rect.w / 30;
	sound_low_destination_rect.h = sound_low_rect.h / 30;

	SDL_Surface* sound_middle_surface = IMG_Load("../Resources/middle.png");
	sound_middle_button = SDL_CreateTextureFromSurface(g_renderer, sound_middle_surface);
	SDL_FreeSurface(sound_middle_surface);

	SDL_QueryTexture(sound_middle_button, NULL, NULL, &sound_middle_rect.w, &sound_middle_rect.h);
	sound_middle_destination_rect.x = 650;
	sound_middle_destination_rect.y = 520;
	sound_middle_destination_rect.w = sound_middle_rect.w / 30;
	sound_middle_destination_rect.h = sound_middle_rect.h / 30;

	SDL_Surface* sound_loud_surface = IMG_Load("../Resources/loud.png");
	sound_loud_button = SDL_CreateTextureFromSurface(g_renderer, sound_loud_surface);
	SDL_FreeSurface(sound_loud_surface);

	SDL_QueryTexture(sound_loud_button, NULL, NULL, &sound_loud_rect.w, &sound_loud_rect.h);
	sound_loud_destination_rect.x = 720;
	sound_loud_destination_rect.y = 520;
	sound_loud_destination_rect.w = sound_loud_rect.w / 30;
	sound_loud_destination_rect.h = sound_loud_rect.h /30;

	
	//background music
	// intro music
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	g_intro_music = Mix_LoadMUS("../Resources/intro_bg.mp3");
	Mix_FadeInMusic(g_intro_music, -1, 1000);

}

void Update_Intro()
{
}


void Render_Intro()
{
	//(g_renderer, 255, 255, 255, 255);
	//SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	SDL_RenderCopy(g_renderer, g_texture_intro, &g_source_rectangle_intro, &g_destination_rectangle_intro);

	SDL_RenderCopy(g_renderer, title_texture_intro, &title_rect, &title_destination_rect);

	SDL_RenderCopy(g_renderer, infinity_texture_intro, &infinity_rect, &infinity_destination_rect);

	SDL_RenderCopy(g_renderer, story_texture_intro, &story_rect, &story_destination_rect);

	SDL_RenderCopy(g_renderer, sound_texture_intro, &sound_rect, &sound_destination_rect);

	SDL_RenderCopy(g_renderer, sound_low_button, &sound_low_rect, &sound_low_destination_rect);

	SDL_RenderCopy(g_renderer, sound_middle_button, &sound_middle_rect, &sound_middle_destination_rect);

	SDL_RenderCopy(g_renderer, sound_loud_button, &sound_loud_rect, &sound_loud_destination_rect);

	SDL_RenderPresent(g_renderer); // draw to the screen
}



void HandleEvents_Intro()
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

				if (mouse_x > story_destination_rect.x &&
					mouse_y > story_destination_rect.y &&
					mouse_x < story_destination_rect.x + story_destination_rect.w &&
					mouse_y < story_destination_rect.y + story_destination_rect.h)
				{
					Init_Stage1();
					startTime_s1 = SDL_GetTicks();
					g_current_game_phase = PHASE_STAGE1;
				}

				else if (mouse_x > infinity_destination_rect.x &&
					mouse_y > infinity_destination_rect.y &&
					mouse_x < infinity_destination_rect.x + infinity_destination_rect.w &&
					mouse_y < infinity_destination_rect.y + infinity_destination_rect.h)
				{					
					g_current_game_phase = PHASE_DRESSROOM;
				}

				if (mouse_x >sound_low_destination_rect.x &&
					mouse_y > sound_low_destination_rect.y &&
					mouse_x < sound_low_destination_rect.x + sound_low_destination_rect.w &&
					mouse_y < sound_low_destination_rect.y + sound_low_destination_rect.h)
				{
					std::cout << "low" << std::endl;
					Mix_VolumeMusic(50);
				}

				else if (mouse_x > sound_middle_destination_rect.x &&
					mouse_y > sound_middle_destination_rect.y &&
					mouse_x < sound_middle_destination_rect.x + sound_middle_destination_rect.w &&
					mouse_y < sound_middle_destination_rect.y + sound_middle_destination_rect.h)
				{
					std::cout << "middle" << std::endl;
					Mix_VolumeMusic(100);
				}

				else if (mouse_x > sound_loud_destination_rect.x &&
					mouse_y > sound_loud_destination_rect.y &&
					mouse_x < sound_loud_destination_rect.x + sound_loud_destination_rect.w &&
					mouse_y < sound_loud_destination_rect.y + sound_loud_destination_rect.h)
				{
					std::cout << "loud" << std::endl;
					Mix_VolumeMusic(300);
				}
			}

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				g_flag_running = false;
			}
			else if (event.key.keysym.sym == SDLK_0) //0 누르면 무한
			{
				Init_Infinite();
				startTime = SDL_GetTicks();
				g_current_game_phase = PHASE_INFINITE;
			}
			else if (event.key.keysym.sym == SDLK_1) //1 누르면 스테이지1
			{
				Init_Stage1();
				startTime_s1 = SDL_GetTicks();
				g_current_game_phase = PHASE_STAGE1;
			}
			else if (event.key.keysym.sym == SDLK_2)
			{
				Init_Stage2();
				startTime_s2 = SDL_GetTicks();
				g_current_game_phase = PHASE_STAGE2;
			}
			else if (event.key.keysym.sym == SDLK_3)
			{
				Init_Stage3();
				startTime_s3 = SDL_GetTicks();
				g_current_game_phase = PHASE_STAGE3;
			}
			else if (event.key.keysym.sym == SDLK_4)
			{
				Init_Stage4();
				startTime_s4 = SDL_GetTicks();
				g_current_game_phase = PHASE_STAGE4;
			}
			else if (event.key.keysym.sym == SDLK_5)
			{
				Init_Stage5();
				startTime_s5 = SDL_GetTicks();
				g_current_game_phase = PHASE_STAGE5;
			}

		default:
			break;
		}
		}
	}
}


void Clear_Intro()
{
	SDL_DestroyTexture(g_texture_intro);
	SDL_DestroyTexture(title_texture_intro);
	SDL_DestroyTexture(infinity_texture_intro);
	SDL_DestroyTexture(story_texture_intro);
	SDL_DestroyTexture(sound_texture_intro);
	SDL_DestroyTexture(sound_low_button);
	SDL_DestroyTexture(sound_middle_button);
	SDL_DestroyTexture(sound_loud_button);

	Mix_FreeMusic(g_intro_music);
	Mix_CloseAudio();
}