#include "masterVisual.h"
#include "utilities.h"


constexpr int word_size = 4;
string løsning = randomizeString(word_size, 'A', 'F');
void playMastermindVisual() {
	MastermindWindow mwin{900, 20, winW, winH, 4, "Mastermind"};
	
    cout << "Løsnig: " << løsning << endl;
    string gjett;
    int forsøk = 0;
    do {
        gjett = mwin.getInput(word_size, 'A', 'F');
		addGuess(mwin, gjett, 'A');
		addFeedback(mwin, checkCharAndPosition(løsning, gjett), checkChar(løsning, gjett));
        cout << "\n Du har " << checkCharAndPosition(løsning, gjett) << " på rett posisjon." << endl
        << "Du har " << checkChar(løsning, gjett) << " rette boksatver." << endl;
        forsøk++;
        if (checkCharAndPosition(løsning, gjett) == word_size) {
            cout << "Gratulerer, du klarte det! " << endl;
			mwin.drawGuessesAndFeedbacks();
			mwin.wait_for_close();
        }
        if (checkCharAndPosition(løsning, gjett) < word_size && forsøk == word_size) {
            cout << "Det ble dessverre tap. Vil du spille igjen (J/N) " << endl;
			mwin.drawGuessesAndFeedbacks();
			mwin.wait_for_close();
        }
    } while (checkCharAndPosition(løsning, gjett) < word_size && forsøk < 7);
    string spille_igjen = "N";
    cout << "Vil du spille igjen (J/N) " << endl;
    cin >> spille_igjen;
    if (spille_igjen == "J"){
        playMastermind();
    }
	mwin.wait_for_close();
}


void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess user_guess{code, startLetter};
	mwin.guesses.push_back(user_guess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback user_feedback {correctPosition, correctCharacter};
	mwin.feedbacks.push_back(user_feedback);

}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {

		draw_rectangle(Point{padX, 2 * padY}, winW - size * padX, padY, Color::red);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int i = 0; i < size; i++) {
		int color_pos = int(løsning[i])-int('A')+1;
		draw_rectangle(Point{padX*(i+1), 2 * padY}, padX, padY, colorConverter.at(color_pos));
	}

	for (int guessIndex = 1; guessIndex <= static_cast<int>(guesses.size()); guessIndex++)
	{
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 1; i <= size; i++)
		{
			int color_pos = int(guesses[guessIndex-1].code[i-1])-int('A')+1;
			draw_rectangle(Point{padX*2*i-padX, 2*padY*guessIndex+2*padY}, padX, padY, colorConverter.at(color_pos));

		}
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)

	{
		int antall_print = 0;
		for (int i = 0; i < size; i++)
		{
			if (i < feedbacks[feedbackIndex].correctPosition){
				draw_circle({(padX*2*size+padX/2)+(i+1)*(2*radCircle), 2*padY*feedbackIndex+4*padY+padY/2}, radCircle, Color::green);
			} else if (antall_print < (feedbacks[feedbackIndex].correctCharacter-feedbacks[feedbackIndex].correctPosition)) {
				draw_circle({(padX*2*size+padX/2)+(i+1)*(2*radCircle), 2*padY*feedbackIndex+4*padY+padY/2}, radCircle, Color::yellow);
				antall_print++;
			} else {
				draw_circle({(padX*2*size+padX/2)+(i+1)*(2*radCircle), 2*padY*feedbackIndex+4*padY+padY/2}, radCircle, Color::black);
			}

		}
	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

