#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string name;
int sword = 2;
int armor = 2;
int vamp = 3;

class NameList {
public:
	vector<string> names;

	void addName(string newName) {
		names.push_back(newName);
	}

	void sortNames() {
		sort(names.begin(), names.end());
	}

	bool searchName(string searchName) {
		return find(names.begin(), names.end(), searchName) != names.end();
	}

	void displayNames() {
		for (const string& n : names) {
			cout << n << endl;
		}
	}
};

void goCheck() {
	if (vamp <= 0) {
		cout << "You won. The beast lies on the ground. It's body lifeless as it slowly turns to ash. Looking around, there seems to be another room hidden behind a book shelf.\nTREASURE!!!!\nTaking the treasure, you emerge from the cave. Looking to the world as you now have been reborn. You ventured into the cave as " << name << " the adventurer.\nBut now, you shall be called " << name << ", the vampire slayer.\n.\n.\n.\n.\nTHE END";
		exit(0);
	}
}

void roomFINAL() {
	char choice7;
	cout << "This is it. The final battle. Your eyes lock as it swiped its claws. Act quick!\nA. Dodge\nB. Brace\n";
	cin >> choice7;
	if (choice7 == 'A') {
		if (armor <= 2) {
			cout << "You dodge the blow and land a counterattack.\n";
			vamp -= 1;
			goCheck();
			cout << "\"THAT HURT!\" It was not enough. The vampire stabbed you back.\nYou died";
			exit(0);
		}
		if (armor >= 3) {
			cout << "Your armor was too heavy!\nThe vampire got your arm. Without your sword arm, death was near. The vampire sank its teeth on your neck.\nYou died";
			exit(0);
		}
	}
	if (choice7 == 'B') {
		if (armor <= 2) {
			cout << "The vampire's attack pierced through your armor. You fell at the floor as you see the beast laugh, licking your blood off its claws.\nYou died";
			exit(0);
		}
		if (armor >= 3) {
			cout << "Your armor withstood the swipe. An opening!\nYou land a massive hit!";
			vamp -= 2;
			goCheck();
		}
	}
}

void roomSW() {
	char choice6;
	cout << "You take out your sword as you warily walk towards the coffin. Something seems strange. The coffin doesn't look right.\nIT'S OPEN\nYou manage just in time to block a strike from behind.\n\"Foolish adventurer. You dare disturb my slumber?\"\n";
	cout << "A. Slash at the beast\nB. Try to reason with it\n";
	cin >> choice6;
	if (choice6 == 'A') {
		cout << "You slash at the beast.\n";
		if (sword == 4) {
			cout << "The beast recoils in pain. \"Silver!\" It leaves a huge gash on his chest. One more hit and you are the victor\n";
			vamp -= 2;
			roomFINAL();
		}
		if (sword == 3) {
			cout << "You land a good hit.\n";
			vamp -= 1;
			roomFINAL();
		}
		if (sword <= 2) {
			cout << "But it caught your sword in its hand. \"You try to kill me with this....stick? HAHAHAHA\" The vampire laughs as he shatters your sword and pierces your heart.\nYou died.";
			exit(0);
		}
	} else {
		cout << "There is no reasoning to a demon.\nYou died.";
		exit(0);
	}
}

void roomBC() {
	cout << "You take out your torch and approach the coffin. The flames set the wooden coffin ablaze.\nIs it dead?\n";
	if (armor >= 2) {
		cout << "A sharp pain emerges from your back.\nIts awake!\nThe vampire backs off but you manage to land a clean counter attack.\n";
		vamp -= 1;
		armor -= 1;
		roomFINAL();
	} else {
		cout << "A sharp pain emerges from your back. You look down to see the vampire's hand. Pierced through your chest.\n\"How fun. A meal after my slumber.\"\nYou died.";
		exit(0);
	}
}

void pathFR() {
	char choice5;
	cout << "\n.\n.\n.\n.\n.\nThis is it.\nThe final chamber\nThe place in where there are only 2 possible outcomes.\nWill a new legend be born? Or will another fool's soul be trapped eternity in this ghastly place.\nUnlike the cave from before, this chamber resembles a house. With tapestries hanging from the walls and stone furniture, it would make sense if someone actually lived here. But in this case, that someone is a creature from the night. Located in the center is a wooden coffin. Carved with beautiful symbols and colors, it fits the aesthetic of a royal. A royal vampire.\n";
	cout << name << ". Make your move.\nA. Use your torch to burn the coffin\nB. Take out your sword and walk towards the coffin\nC. Turn back and leave\n";
	cin >> choice5;
	if (choice5 == 'A')
		roomBC();
	if (choice5 == 'B')
		roomSW();
	if (choice5 == 'C') {
		cout << "It's too late to turn back. Your hesitation caused an opening. The vampire got you.\nYou died";
		exit(0);
	}
}

void pathWW() {
	char choice1;
	cout << "A nagging feeling can't seem to escape your throat. The reason why soon reveals itself.\nA WEREWOLF!!!!\nUsing your quick senses, you quickly hide from the evil beast. What will you do?\n";
	cout << "A. Attack\nB. Wait and stay hidden\nC. Try to talk\n";
	cin >> choice1;
	if (choice1 == 'A') {
		cout << "You foolish man. Attacking a werewolf without silver is a death sentence.";
		exit(0);
	}
	if (choice1 == 'B') {
		cout << "A werewolf's sense of smell is impeccable. It spots you. You try to fight back but it disposes of you quickly.";
		exit(0);
	}
	if (choice1 == 'C') {
		char choice3;
		cout << "It did not attack.\nStrange....\nThe seemingly evil beast speaks!\n";
		cout << "\"I was once human. Until the wretched monsters in this cave cursed me.\"\n";
		cout << "\"While I cannot venture away from this area, I believe that I can aid you if you follow me\".";
		cout << "What will you do " << name << "?\n";
		cout << "A. Trust him\nB. Stab him in the back\nC. Refuse\n";
		cin >> choice3;
		if (choice3 == 'A') {
			cout << "\nThe cursed man led you to a room of many riches. From ancient armor to beautiful paintings. But the one that you need most is displayed upon a pedestal.\n";
			cout << "A silver sword.\nNow you are ready to face them.\n";
			sword += 2;
			pathFR();
		} else if (choice3 == 'B') {
			cout << "\nHe let his guard down. Now is the time to strike!\n";
			if (sword >= 2) {
				cout << "It's dead. You won. The beast lies on your feet. But a cough escapes from the beast's mouth.\n";
				cout << "\"T-Thank you....\"\nYou have slain the beast. But it seems that the evil one in here is you.\n";
				cout << "But it is without naught as you found a sharpening stone in the werewolf's house.\nYou proceed to the final room.\n";
				sword += 1;
				pathFR();
			} else {
				cout << "Your sword broke against the beast's back. It roared \"You dare try to fool me?!\" The beast killed you.\nViolence is not always the answer";
				exit(0);
			}
		} else if (choice3 == 'C') {
			cout << "A shame. But I cannot keep you any longer. You may proceed to the final room.";
			pathFR();
		}
	}
}

void pathGY() {
	char choice2;
	cout << "A ghastly sight met your eyes as you venture deeper into the seemingly normal path. Dusty bones litter the path as you see rats scurrying from your footsteps. But one pile of bones stands out from the rest.\nAn adventurer.\nOne of the poor souls before you.\nLooking closer, a journal sat on what remains of his hand. You pick up the book.\nJournal Entry - 4th of Rain's Hand, 4E 203\nThe winding trails of Skyrim have led me to an unexpected discovery...a crypt hidden amidst the craggy peaks, known to the locals as Blut-Trinker.\n";
	cout << "The whispers in taverns and dark corners spoke of vampiric tales, and curiosity led me to uncover the entrance concealed by illusionary trickery. The passage into Blut-Trinker Crypt was not for the faint-hearted, marked only by the faint echoes of distant bats and an eerie, blood-red glow.\n";
	cout << "The air clung to my skin, thick with the scent of ancient secrets and the chill of the undead. Navigating the labyrinthine catacombs proved a challenge, as the crimson torches cast long shadows on the cold stone walls.\n";
	cout << "The murals on the tapestries depicted vampiric prowess and the conquests of a bygone stories of immortal beings defying the passage of time. Deeper within, a grand chamber unfolded, revealing an unsettling sight. An altar, shrouded in darkness, stood as a focal point.\n";
	cout << "Coffins of various shapes lay dormant around it, each holding the slumbering undead. I could feel the presence of Lord Vlad, the ancient vampire said to rule over this crypt.\n";
	cout << "As I turn back to leave, an arrow pierced my knee.\nIt's him.\nI ran. I ran as fast as I could.\nIf anybody is reading this, take my advice. Turn back and never look back. If you are a fool like me, take my armor. Though it looks dull, it should ward off attacks.\n";
	cout << "\nThe choice is now brave adventurer.\nA. Run\nB. Continue\n";
	cin >> choice2;
	if (choice2 == 'A') {
		cout << "You ran. Ran like you never ran before. Luckily, no one seemed to follow. Though you left without riches, you managed to preserve the greatest treasure of all.\nYour life.\n" << name << " an ex-adventurer that retired due to cowardice. A living one at least.\nWhether you consider it a win or a loss, that is for you, " << name << " to decide.";
		exit(0);
	} else if (choice2 == 'B') {
		cout << "You fool. But you are brave.\nWell done.\nYou take the armor\nProceed to the final room.\n";
		armor += 1;
		pathFR();
	}
}

void pathBH() {
	char choice4;
	cout << "Goblins emerge from behind. They landed a sneak attack. Your armor got damaged.\n";
	armor -= 1;
	cout << "You try to retaliate.\n";
	if (sword >= 1) {
		cout << "You succeed. It drove them away. Towards the only exit. The only place left is forward.\nA. Go right\nB. Go left\n";
		cin >> choice4;
		if (choice4 == 'A')
			pathWW();
		else
			pathGY();
	} else {
		cout << "You failed.\nDying to a goblin?\nPathetic";
		exit(0);
	}
}

int main() {
	char choice;
	NameList nameList;
	cout << "This is a dungeon crawling game. You play as an adventurer looking for treasure. Choose the correct choices and you may emerge from the dungeon with riches and fame.";
	cout << "Don't, and be one of the numerous souls trapped in the depths. Choose wisely.\nUSE CAPITAL LETTERS FOR CHOICES\n";
	cout << "\nIn the desolate land of Tamriel, a looming structure has emerged...the Blut-Trinker Crypt.";
	cout << "Whispers of ancient treasures and unimaginable power surround it, drawing adventurers from all corners.";
	cout << "As you take your first steps, the adventure begins. The Blut-Trinker Crypt awaits, filled with peril, mystery, and the promise of glory.";
	cout << "Will you conquer its depths or become just another lost soul within its walls? The choice is yours.\n";
	cout << "\nBut first, what is your name, brave adventurer? ";
	cin >> name;
	cout << "\nYes. " << name << ". A worthy name for a brave adventurer. You descend on the dark depths of the dungeon equipped only with a simple sword, leather clothes, a torch, and a dream of vast riches.\n";
	cout << "Exploring the tunnels you soon hear a slight chitter above. Do you:\nA. Swing your sword above\nB. Shine your torch\nC. Ignore and move on\n";
	cin >> choice;
	if (choice == 'A') {
		cout << "\nIt's just a bat. But your swing resulted in your sword to be stuck at the stone. It chipped.\n";
		sword -= 1;
	} else if (choice == 'B') {
		cout << "\nIt's just a bat. You move on.\n";
	} else if (choice == 'C') {
		cout << "You move on";
	}
	cout << "\nGoing deeper, you find yourself on a fork. The left looks ominous with bones scattered upon the path. The right looks like normal.\nWhat will you do?\n";
	cout << "A. Go right\nB. Go left\nC. Turn back\n";
	cin >> choice;
	switch (choice) {
	case 'A':
		pathWW();
		break;
	case 'B':
		pathGY();
		break;
	case 'C':
		pathBH();
		break;
	}
	cout << "Would you like to add your name to the list of adventurers? (Y/N)\n";
	char addChoice;
	cin >> addChoice;
	if (addChoice == 'Y') {
		nameList.addName(name);
		nameList.sortNames();
		cout << "Adventurers List:\n";
		nameList.displayNames();
	}
	return 0;
}
