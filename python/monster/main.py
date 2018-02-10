import sys

class Main:
    max_width = 5
    max_height = 5
    character_alive = True
    character_won = False
    monster_awake = False
    monster_awakened = False
    monster_move_per_turn = 2

    def __init__(self):
        pass
    def display_menu(self):
        menu_list = ['Start New Game', '[Save_Game]', '[Load Game]',
                    'Customize Setup', 'Exit']
        print('Type the number of your choice')
        print()
        for i in range(1, len(menu_list) + 1):
            print(str(i) + ' ' + menu_list[i -1])
        choice = input('Your Choice: ')
        self.menu_choice(choice)

    def menu_choice(self, choice):
        try:
            choice = int(choice)
        except ValueError:
            choice = 0

        if (choice == 1):
            pass
        elif (choice == 2):
            pass
        elif (choice == 3):
            pass
        elif (choice == 4):
            pass
        elif (choice == 5):
            sys.exit(0)
        else:
            print('That was\'t a valid option, please try again')
            self.display_menu()
monster = Main()
monster.display_menu();
