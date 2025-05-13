#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <time.h>

int main(void)
{
    setlocale(LC_ALL, "english");

    char guess[6], word[6], word_check[10], key, words[1000][6] = {"aback", "abate", "abide", "about", "abyss", "acids", "acrid", "acute", "added", "adieu", "adopt", "adult", "affix", "after", "agate", "aging", "agree", "aides", "aired", "album", "alias", "alike", "alley", "alloy", "alone", "aloud", "alter", "amaze", "amend", "amity", "ample", "angel", "angry", "ankle", "annul", "anvil", "aping", "apply", "areas", "arise", "arose", "arson", "aside", "aspen", "asset", "atlas", "atone", "audio", "aught", "auras", "avers", "avows", "award", "awoke", "azure", "backs", "badly", "baize", "bales", "banal", "bangs", "banns", "bared", "barns", "based", "basic", "basis", "batch", "baths", "beach", "beaks", "beard", "beaux", "befit", "beget", "begun", "belle", "below", "bends", "berth", "besom", "bided", "bigot", "billy", "birch", "bison", "blade", "blank", "blaze", "bleed", "bless", "blink", "blocs", "bloom", "blows", "bluff", "blush", "boast", "bodes", "boils", "bombs", "bones", "booby", "boons", "booth", "booze", "bores", "bough", "bowed", "bowls", "boxes", "braid", "brand", "brave", "brawn", "breed", "brick", "brier", "brine", "briny", "broil", "brook", "brown", "brunt", "bucks", "bugle", "bulbs", "bulky", "bumps", "buoys", "burnt", "burst", "butte", "buyer", "cabin", "cache", "caged", "caked", "calms", "cameo", "candy", "canoe", "caper", "cards", "cargo", "carts", "cases", "casts", "cause", "cavil", "ceded", "chafe", "chair", "chant", "charm", "chase", "cheap", "cheek", "chess", "chide", "chill", "chink", "chirp", "chops", "chuck", "chunk", "chute", "cinch", "cites", "civil", "clamp", "clank", "clash", "claws", "clefs", "clews", "climb", "clink", "clock", "close", "clout", "clubs", "clump", "coals", "cobra", "codes", "colds", "colts", "comes", "comma", "conic", "cools", "coral", "corks", "costs", "cough", "coupe", "cover", "covey", "coyly", "crack", "cramp", "crape", "crate", "craze", "cream", "creek", "crept", "crews", "cried", "crime", "croak", "crony", "cross", "crown", "cruel", "crust", "cubic", "cults", "cures", "curry", "curve", "daddy", "daisy", "dames", "dandy", "darts", "datum", "dawns", "dealt", "death", "debts", "decks", "deeds", "defer", "delay", "delve", "dense", "depth", "deter", "diary", "dicta", "dikes", "dined", "dingy", "discs", "ditto", "dived", "dizzy", "doers", "doled", "domes", "doors", "doted", "dough", "downs", "dozed", "drags", "drama", "drape", "draws", "dream", "dried", "drift", "drink", "droll", "drops", "drown", "drunk", "ducat", "ducts", "dukes", "dumps", "dunes", "dupes", "dwarf", "dying", "eagle", "earns", "easel", "eater", "ebony", "edict", "egged", "elate", "elect", "elite", "elves", "empty", "endow", "ennui", "enter", "epics", "equip", "erred", "ether", "event", "evoke", "excel", "exist", "extol", "eying", "faced", "faded", "faint", "faith", "false", "fangs", "fares", "fatal", "fatty", "fauns", "feast", "feels", "fells", "feral", "fetch", "fetus", "fewer", "field", "fifes", "fight", "files", "filly", "filth", "finds", "fines", "fiord", "firms", "fists", "fixed", "fjord", "flair", "flame", "flare", "fleck", "flesh", "flies", "flirt", "flock", "floor", "flour", "flows", "fluid", "flung", "flyer", "focal", "foils", "folio", "foods", "force", "forgo", "forte", "forty", "fount", "foxes", "frame", "fraud", "freer", "frets", "frill", "frogs", "frost", "froze", "fuels", "fumed", "fungi", "furze", "fussy", "gaily", "galls", "gamma", "gaped", "gasps", "gauge", "gauzy", "gayer", "gazer", "geese", "genre", "germs", "gibes", "gilds", "gipsy", "girth", "glade", "glass", "glean", "glint", "gloom", "glove", "gnash", "gnome", "goats", "golly", "goods", "gored", "gotta", "gouty", "grace", "grain", "grant", "grasp", "grave", "great", "greet", "grill", "grind", "grips", "groin", "gross", "growl", "grubs", "grunt", "guess", "guild", "guise", "gulls", "gypsy", "hails", "haled", "halve", "hangs", "harem", "harps", "harsh", "hasty", "hater", "havoc", "heads", "heaps", "heart", "heave", "heeds", "helix", "helps", "herds", "hewed", "hilly", "hinge", "hires", "hoard", "hoist", "homes", "hoofs", "hoots", "horde", "horse", "hotly", "house", "howls", "human", "humus", "hurls", "husks", "hydra", "icily", "ideas", "idled", "idyll", "imbue", "inane", "inept", "ingot", "inter", "irked", "isles", "items", "jaded", "jeans", "jetty", "joins", "joker", "joust", "juice", "junks", "karma", "ketch", "kicks", "kinds", "kites", "knead", "knell", "knits", "knoll", "knows", "laces", "ladle", "laity", "lamed", "lance", "lanky", "larch", "larks", "lasts", "lathe", "lawns", "leafy", "leans", "learn", "least", "leech", "lemme", "lever", "licks", "lifts", "liken", "lilac", "limes", "linen", "lingo", "lists", "liver", "llama", "loans", "lobes", "locus", "loges", "loins", "looms", "loose", "loses", "lousy", "loves", "lowly", "lucky", "lumpy", "lunge", "lured", "lurks", "lutes", "lynch", "madam", "maids", "maize", "makes", "manes", "mango", "manly", "manse", "mares", "marsh", "mason", "mated", "maxim", "mazes", "means", "medal", "melon", "mends", "meres", "merry", "meted", "midst", "milch", "mills", "mince", "miner", "mints", "miser", "mixed", "moats", "modem", "molar", "money", "moods", "moors", "moral", "motes", "motor", "mount", "mouth", "moves", "mower", "mules", "mumps", "murky", "music", "muted", "myths", "naive", "names", "natal", "navel", "necks", "neigh", "never", "nicer", "night", "nobly", "nomad", "noose", "noses", "notes", "nudge", "oaken", "oasis", "obese", "ocean", "oddly", "offer", "olden", "omits", "oozed", "opens", "opium", "order", "other", "ounce", "ovals", "overt", "owner", "paces", "padre", "pages", "paint", "paler", "palmy", "panes", "pansy", "papas", "parka", "parse", "pasha", "patch", "patio", "pawed", "payer", "peaks", "pears", "pedal", "pelts", "penis", "perch", "pesos", "petty", "phone", "picks", "piety", "piled", "pilot", "pines", "pints", "piper", "pitch", "place", "plait", "plans", "plays", "pleas", "plots", "plumb", "plush", "poesy", "poise", "pokes", "polka", "pools", "poppy", "pores", "poser", "posts", "pours", "prate", "preys", "pride", "prime", "prism", "probe", "props", "proud", "prows", "prune", "pudgy", "pulls", "pumps", "puppy", "purge", "putty", "quail", "quart", "queen", "query", "quick", "quilt", "quite", "quote", "rabid", "races", "radio", "rages", "rains", "rajah", "rally", "ranks", "rares", "ratio", "raves", "razor", "reads", "reals", "rears", "rebut", "reedy", "reels", "refit", "reins", "relic", "renew", "repel", "resin", "revue", "ricks", "ridge", "right", "rills", "rinse", "riper", "rises", "rites", "river", "roams", "robed", "rocks", "roles", "roofs", "roomy", "roped", "rosin", "round", "routs", "rowdy", "ruder", "ruled", "runes", "rural", "sabre", "safer", "sahib", "saith", "sally", "salts", "salvo", "saner", "satyr", "saved", "scald", "scaly", "scant", "scars", "scion", "scoop", "scorn", "scowl", "scrip", "seals", "seats", "sedge", "seeks", "seize", "sends", "serge", "seven", "sewer", "shade", "shake", "shall", "shams", "share", "shave", "shear", "sheep", "sheik", "shied", "shins", "shire", "shoal", "shone", "shoot", "shorn", "shout", "shows", "shrew", "shuns", "sibyl", "siege", "sight", "silks", "silly", "singe", "siren", "sixes", "sized", "skein", "skill", "skips", "skull", "slack", "slake", "slaps", "slats", "sleds", "sleet", "slick", "slime", "slink", "sloop", "sloth", "slums", "slush", "small", "smear", "smile", "smith", "smoky", "snags", "snaky", "snarl", "sniff", "snore", "snows", "soapy", "socks", "soils", "solid", "songs", "sooty", "sorts", "sound", "south", "space", "spank", "spark", "spawn", "speck", "spelt", "sperm", "spied", "spill", "spins", "spite", "spoil", "spool", "spore", "spout", "sprig", "spurs", "squat", "stack", "stags", "stair", "stalk", "stand", "stark", "state", "stead", "steam", "steep", "steps", "stick", "still", "stint", "stoic", "stony", "stoop", "stork", "stout", "straw", "strip", "studs", "stump", "style", "sugar", "suits", "sully", "surer", "swain", "sward", "swear", "sweet", "swift", "swine", "swish", "sword", "swung", "tabby", "tacit", "taint", "tales", "talon", "tanks", "tardy", "tarts", "tasty", "taxed", "teams", "teems", "tells", "temps", "tenor", "tents", "terms", "testy", "theft", "there", "thief", "thing", "thong", "three", "throe", "thump", "tibia", "tides", "tight", "tiles", "timed", "tinge", "tired", "title", "today", "token", "tomes", "tongs", "tooth", "toque", "torts", "touch", "towed", "towns", "trace", "trade", "trait", "traps", "tread", "trees", "triad", "trice", "tries", "trips", "troop", "trout", "truer", "trunk", "truth", "tufts", "tuned", "turns", "twain", "twice", "twins", "tying", "udder", "uncle", "undid", "union", "unity", "until", "urban", "urine", "usher", "usurp", "vague", "valid", "vanes", "vault", "veins", "venom", "verbs", "verve", "vexes", "vices", "vigil", "vines", "virus", "vista", "vixen", "vodka", "voile", "voted", "vouch", "vying", "wages", "wails", "waive", "wakes", "waltz", "wanes", "wares", "warts", "watch", "waver", "waxen", "weary", "weeds", "weeps", "welch", "whack", "wheat", "where", "while"};
    int i = 0, j = 0, guess_count = 0, result, easter_egg = 0, rand_index, option;
    word[0] = '\0';
    srand(time(NULL));

    system("COLOR F0");
    SetConsoleTitle("Termo");
    system("MODE CON: COLS=85 LINES=20");

    while (key != 13)
    {
        system("cls");

        if (key <= 75)
        {
            printf("\t   /________/\\/_____/\\ /_____/\\  /__//_//_/\\ /_____/\\     \n\t   \\__.::.__\\/\\::::_\\/_\\:::_ \\ \\ \\::\\| \\| \\ \\\\:::_ \\ \\  \n\t      \\::\\ \\   \\:\\/___/\\\\:(_) ) )_\\:.      \\ \\\\:\\ \\ \\ \\  \n\t       \\::\\ \\   \\::___\\/_\\: __ `\\ \\\\:.\\-/\\  \\ \\\\:\\ \\ \\ \\  \n\t        \\::\\ \\   \\::___\\/_\\: __ `\\ \\\\:.\\-/\\  \\ \\\\:\\ \\ \\ \\  \n\t         \\::\\ \\   \\:\\____/\\\\ \\ `\\ \\ \\\\. \\  \\  \\ \\\\:\\_\\ \\ \\ \n\t          \\__\\/    \\_____\\/ \\_\\/ \\_\\/ \\__\\/ \\__\\/ \\_____\\/ ");
            printf("\n\n\n\t\t\t     \n\t\t\t     ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            printf("1 Player");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            printf("\t   2 Players\n\n\n\n\n\n\n\n\n");
            option = 0;
        }
        else
        {
            printf("\t   /________/\\/_____/\\ /_____/\\  /__//_//_/\\ /_____/\\     \n\t   \\__.::.__\\/\\::::_\\/_\\:::_ \\ \\ \\::\\| \\| \\ \\\\:::_ \\ \\  \n\t      \\::\\ \\   \\:\\/___/\\\\:(_) ) )_\\:.      \\ \\\\:\\ \\ \\ \\  \n\t       \\::\\ \\   \\::___\\/_\\: __ `\\ \\\\:.\\-/\\  \\ \\\\:\\ \\ \\ \\  \n\t        \\::\\ \\   \\::___\\/_\\: __ `\\ \\\\:.\\-/\\  \\ \\\\:\\ \\ \\ \\  \n\t         \\::\\ \\   \\:\\____/\\\\ \\ `\\ \\ \\\\. \\  \\  \\ \\\\:\\_\\ \\ \\ \n\t          \\__\\/    \\_____\\/ \\_\\/ \\_\\/ \\__\\/ \\__\\/ \\_____\\/ ");
            printf("\n\n\n\n\t\t\t     1 Player\t   ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_INTENSITY);
            printf("2 Players");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            printf("\n\n\n\n\n\n\n\n\n");
            option = 100;
        }
        key = getch();
    }

    system("cls");

    printf("Guess the correct word in 6 attempts.\nAfter each guess, the letters will show how close you are to the solution.\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    printf("T");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf("URMA\n\n");
    printf("The letter ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    printf("T");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf(" is in the correct position.\n\n");
    printf("VI");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    printf("O");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf("LA\n\nThe letter ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    printf("O");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf(" is in the word but in the wrong position.\n\nPUL");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
    printf("G");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf("A\n\nThe letter ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
    printf("G");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    printf(" is not in the word.\n\nAccents are not considered in the hints.\nWords may contain repeated letters.");
    getch();
    system("cls");

    if (option > 75)
    {
        printf("Choose a 5-letter word for the game: ");
        for (i = 0; i < 5; i++)
        {
            word[i] = getch();
            if (i < 5) printf("*");
            if (word[i] > 90) word[i] -= 32;//transform the letters to be all capital letters
        }

        while ((word[0] > 90) || (word[0] < 65) || (word[1] > 90) || (word[1] < 65) || (word[2] > 90) || (word[2] < 65) || (word[3] > 90) || (word[3] < 65) || (word[4] > 90) || (word[4] < 65))
        {
            easter_egg++;
            if (easter_egg == 3)
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_INTENSITY);
                printf(">:( ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
                getch();
            }

            printf("\n\nOnly letters are allowed!");
            getch();
            system("cls");
            printf("Enter a 5-letter word for the game again: ");
            for (i = 0; i < 5; i++)
            {
                word[i] = getch();
                if (i < 5) printf("*");
                if (word[i] > 90) word[i] -= 32;
            }
        }
        system("cls");
    }
    else
    {
        rand_index = rand() % 1000;
        strcpy(word, words[rand_index]);
        for (i = 0; i < 5; i++) word[i] -= 32;
    }

    word[5] = '\0';

    while (guess_count < 6)
    {
        guess_count++;
        strcpy(word_check, word);

        printf("Guess: ");
        scanf("%s", guess);

        setbuf(stdin, NULL);
        fflush(stdin);

        if ((strlen(guess) >= 6) || (strlen(guess) <= 4))
        {
            system("cls");
            printf("Only 5 letters are allowed.");
            getch();
            system("cls");
            guess_count--;
            continue;
        }

        for (i = 0; i < 5; i++)
        {
            if (guess[i] > 90)
                guess[i] -= 32;

            if (guess[i] == word_check[i])
                word_check[i] = '1';
        }

        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; j++)
            {
                if (word_check[i] == '1')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
                    printf("%c", guess[i]);
                    word_check[i] = ' ';
                    i++;
                }
                else if ((guess[i] == word_check[0]) || (guess[i] == word_check[1]) || (guess[i] == word_check[2]) ||
                         (guess[i] == word_check[3]) || (guess[i] == word_check[4]))
                {

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);

                    if (word_check[i] == 1)
                        continue;
                    else if (guess[i] == word_check[0])
                    {
                        printf("%c", guess[i]);
                        i++;
                        word_check[0] = ' ';
                    }
                    else if (guess[i] == word_check[1])
                    {
                        printf("%c", guess[i]);
                        i++;
                        word_check[1] = ' ';
                    }
                    else if (guess[i] == word_check[2])
                    {
                        printf("%c", guess[i]);
                        i++;
                        word_check[2] = ' ';
                    }
                    else if (guess[i] == word_check[3])
                    {
                        printf("%c", guess[i]);
                        i++;
                        word_check[3] = ' ';
                    }
                    else if (guess[i] == word_check[4])
                    {
                        printf("%c", guess[i]);
                        i++;
                        word_check[4] = ' ';
                    }
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                    printf("%c", guess[i]);
                    i++;
                }
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY); // reset to default color
        printf("\n");

        result = strcmp(word, guess);

        if (result == 0)
        {
            system("cls");
            system("color F1");
            printf("\n\n\t\t\t    Congratulations, you won!!!\n\n\t\t          ,,****,,,,,,,,,,,,,,,,,********,,        \n\t\t          ,,    ,,,,,,,,,,*,,,,,,****    ,,        \n\t\t          ,,     ,,,,,*********,,***     ,,        \n\t\t           ,,    ,,,,,,,*****,,,****    ,,         \n\t\t             ,,   ,,,,,,,,,,,,,,***   ,,           \n\t\t                *,,,,,,,,,,,,,,***,,*              \n\t\t                      ,,,,,,,**                    \n\t\t                         ,,*                       \n\t\t                         ,,*                       \n\t\t                        ,,,,*                      \n\t\t                    ,,,,,,,,,,***                  \n\t\t                 %%,,,,,,,,,.,,,,,%&               \n\t\t                 %%.,,,,,,,,,,,,,,&&               \n\t\t                 %%%%%%%%%%%%%%%%&&&&&&&%%%%%%%      \n\n\n");
            getch();
            break;
        }
        else if (guess_count == 6)
        {
            system("cls");
            system("color F4");
            printf("\n\n\t\t\t       Sorry, you lost!!!\n\n\t\t      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t      @@@@@@@@@@@@.               (@@@@@@@@@@@\n\t\t      @@@@@@@@                        (@@@@@@@\n\t\t      @@@@@@                             @@@@@\n\t\t      @@@@                                 @@@\n\t\t      @@@           @@@      @@@@           @@\n\t\t      @@            @@@,     @@@@            @\n\t\t      @.                                     #\n\t\t      @                                      ,\n\t\t      @.               @@@@@@@               #\n\t\t      @@         #@@@@.       ,@@@@*         @\n\t\t      @@@       ,@                 @        @@\n\t\t      @@@@                                 @@@\n\t\t      @@@@@@                             @@@@@\n\t\t      @@@@@@@@#                       @@@@@@@@\n\t\t      @@@@@@@@@@@@&               @@@@@@@@@@@@\n");
            getch();
            system("cls");
            printf("The word was %s", word);
            getch();
            break;
        }
    } //fim while

    return(0);
}
