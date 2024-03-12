#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

void printEmojis(vector<unique_ptr<Emoji>>& emojis, AnimationWindow& win){
	for (unique_ptr<Emoji>& emoji : emojis) {
		emoji->draw(win);
	}
}

vector<unique_ptr<Emoji>> emojis;

int main() {
	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	EmptyFace fjes(Point{300,300}, 50);
	SintFace fjess(Point{400,300}, 50);
	OverrasketFace fjesss(Point{500,300}, 50);
	fjess.draw(win);
	unique_ptr<Emoji> ptrfjes(&fjes);
	emojis.push_back(move(ptrfjes));
	unique_ptr<Emoji> ptrfjess(&fjess);
	emojis.push_back(move(ptrfjess));
	unique_ptr<Emoji> ptrfjesss(&fjesss);
	emojis.push_back(move(ptrfjesss));

	printEmojis(emojis, win);
	win.wait_for_close();

	return 0;
}
