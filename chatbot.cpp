#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

/*
    ============================================================
              RULE-BASED AI CHATBOT
    ============================================================

    Project Requirements:
    1. Continuous input loop using while
    2. Input sanitization
       - Convert input to lowercase
       - Remove unnecessary spaces
       - Remove simple punctuation
    3. Knowledge base containing multiple intents
    4. If-else decision-making logic
    5. Fallback response for unknown inputs
    6. Clean exit strategy
    7. Predefined responses
*/

// ------------------------------------------------------------
// KNOWLEDGE BASE
// ------------------------------------------------------------

map<string, string> knowledgeBase =
{
    // Greetings
    {"greeting",
     "Hello! It is nice to talk to you. How can I help you today?"},

    // Morning
    {"morning",
     "Good morning! I hope you have a wonderful day ahead."},

    // Afternoon
    {"afternoon",
     "Good afternoon! I hope your day is going well."},

    // Evening
    {"evening",
     "Good evening! How has your day been so far?"},

    // How are you
    {"wellbeing",
     "I am doing well, thank you for asking! I am ready to chat with you."},

    // Chatbot introduction
    {"introduction",
     "I am SmartBot, a simple rule-based AI chatbot created using C++."},

    // Abilities
    {"abilities",
     "I can respond to greetings, answer basic questions about AI and computers, tell jokes, provide simple information, and have a small conversation with you."},

    // Artificial Intelligence
    {"ai",
     "Artificial Intelligence, or AI, is a field of computer science that allows machines to perform tasks that normally require human intelligence."},

    // Machine Learning
    {"machine_learning",
     "Machine Learning is a branch of AI in which computers learn patterns from data and use those patterns to make predictions or decisions."},

    // Rule-based chatbot
    {"rule_based",
     "A rule-based chatbot works with predefined rules. It checks the user's input, identifies a matching intent, and provides a predefined response."},

    // Programming
    {"programming",
     "Programming is the process of writing instructions that tell a computer how to perform a particular task."},

    // C++
    {"cpp",
     "C++ is a general-purpose programming language commonly used for software development, games, system applications, and many other types of programs."},

    // Computer
    {"computer",
     "A computer is an electronic device that accepts input, processes information according to instructions, and produces output."},

    // Hardware
    {"hardware",
     "Hardware means the physical parts of a computer, such as the keyboard, mouse, monitor, processor, memory, and storage."},

    // Software
    {"software",
     "Software is a collection of programs and instructions that tells a computer what to do."},

    // Thank you
    {"thanks",
     "You're welcome! I am glad I could help."},

    // Sorry
    {"sorry",
     "No problem at all. Don't worry about it!"},

    // Joke
    {"joke",
     "Why do programmers prefer dark mode? Because light attracts bugs!"},

    // Second joke
    {"another_joke",
     "Why did the computer go to the doctor? Because it had a virus!"},

    // Motivation
    {"motivation",
     "You do not have to do everything at once. Take one step at a time and keep moving forward."},

    // Study
    {"study",
     "Good luck with your studies! Make a simple plan, practice regularly, and remember to take short breaks."},

    // Happy
    {"happy",
     "That is wonderful to hear! I hope your good mood continues."},

    // Sad
    {"sad",
     "I am sorry that you are feeling this way. I hope things get better soon."},

    // Tired
    {"tired",
     "It sounds like you could use some rest. Take a little time for yourself if you can."},

    // Goodbye
    {"goodbye",
     "Goodbye! It was nice talking to you. Take care and have a great day!"}
};


// ------------------------------------------------------------
// FUNCTION: CONVERT INPUT TO LOWERCASE
// ------------------------------------------------------------

string convertToLower(string text)
{
    for (char &character : text)
    {
        character =
            static_cast<char>(
                tolower(
                    static_cast<unsigned char>(character)
                )
            );
    }

    return text;
}


// ------------------------------------------------------------
// FUNCTION: REMOVE EXTRA SPACES
// ------------------------------------------------------------

string removeExtraSpaces(string text)
{
    string result;

    bool previousWasSpace = false;

    for (char character : text)
    {
        if (character == ' ')
        {
            if (!previousWasSpace)
            {
                result += character;
            }

            previousWasSpace = true;
        }
        else
        {
            result += character;
            previousWasSpace = false;
        }
    }

    // Remove space from beginning
    if (!result.empty() && result[0] == ' ')
    {
        result.erase(0, 1);
    }

    // Remove space from end
    if (!result.empty() &&
        result[result.length() - 1] == ' ')
    {
        result.erase(result.length() - 1, 1);
    }

    return result;
}


// ------------------------------------------------------------
// FUNCTION: REMOVE SIMPLE PUNCTUATION
// ------------------------------------------------------------

string removePunctuation(string text)
{
    string result;

    for (char character : text)
    {
        if (character != '?' &&
            character != '!' &&
            character != ',' &&
            character != '.')
        {
            result += character;
        }
    }

    return result;
}


// ------------------------------------------------------------
// FUNCTION: SANITIZE USER INPUT
// ------------------------------------------------------------

string sanitizeInput(string input)
{
    input = convertToLower(input);

    input = removePunctuation(input);

    input = removeExtraSpaces(input);

    return input;
}


// ------------------------------------------------------------
// FUNCTION: CHECK WHETHER INPUT CONTAINS A PHRASE
// ------------------------------------------------------------

bool containsPhrase(string input, string phrase)
{
    return input.find(phrase) != string::npos;
}


// ------------------------------------------------------------
// FUNCTION: DISPLAY WELCOME MESSAGE
// ------------------------------------------------------------

void displayWelcome()
{
    cout << "\n";
    cout << "============================================================\n";
    cout << "                 SMARTBOT CHATBOT\n";
    cout << "             RULE-BASED AI ASSISTANT\n";
    cout << "============================================================\n";

    cout << "Bot: Hello! I am SmartBot.\n";
    cout << "Bot: I am a simple rule-based AI chatbot created in C++.\n";
    cout << "Bot: You can ask me questions or simply have a conversation.\n";
    cout << "Bot: Type 'help' if you want to see what I can understand.\n";
    cout << "Bot: Type 'bye', 'goodbye', 'exit', or 'quit' to leave.\n";

    cout << "============================================================\n";
}


// ------------------------------------------------------------
// FUNCTION: DISPLAY HELP MENU
// ------------------------------------------------------------

void displayHelp()
{
    cout << "\n";
    cout << "----------------------- HELP MENU ---------------------------\n";

    cout << "\nGreetings:\n";
    cout << "  hello\n";
    cout << "  hi\n";
    cout << "  hey\n";
    cout << "  salam\n";
    cout << "  good morning\n";
    cout << "  good afternoon\n";
    cout << "  good evening\n";

    cout << "\nChatbot:\n";
    cout << "  what is your name\n";
    cout << "  who are you\n";
    cout << "  what can you do\n";

    cout << "\nArtificial Intelligence:\n";
    cout << "  what is ai\n";
    cout << "  what is machine learning\n";
    cout << "  what is a rule based chatbot\n";

    cout << "\nComputer Science:\n";
    cout << "  what is programming\n";
    cout << "  what is c++\n";
    cout << "  what is hardware\n";
    cout << "  what is software\n";

    cout << "\nConversation:\n";
    cout << "  how are you\n";
    cout << "  thank you\n";
    cout << "  i am happy\n";
    cout << "  i am sad\n";
    cout << "  i am tired\n";

    cout << "\nFun:\n";
    cout << "  tell me a joke\n";
    cout << "  tell me another joke\n";

    cout << "\nOther:\n";
    cout << "  motivate me\n";
    cout << "  i have an exam\n";

    cout << "\nExit:\n";
    cout << "  bye\n";
    cout << "  goodbye\n";
    cout << "  exit\n";
    cout << "  quit\n";

    cout << "\n------------------------------------------------------------\n";
}


// ------------------------------------------------------------
// FUNCTION: CHECK EXIT COMMAND
// ------------------------------------------------------------

bool isExitCommand(string input)
{
    if (input == "bye" ||
        input == "goodbye" ||
        input == "good bye" ||
        input == "exit" ||
        input == "quit" ||
        input == "see you" ||
        input == "see you later" ||
        input == "talk to you later" ||
        input == "i have to go" ||
        input == "i am leaving")
    {
        return true;
    }

    return false;
}


// ------------------------------------------------------------
// FUNCTION: FIND USER INTENT
//
// This is the main decision-making part of the chatbot.
// It uses if-else logic to identify the user's intention.
// ------------------------------------------------------------

string identifyIntent(string input)
{
    // --------------------------------------------------------
    // GREETING INTENT
    // --------------------------------------------------------

    if (input == "hello" ||
        input == "hi" ||
        input == "hey" ||
        input == "hiya" ||
        input == "howdy" ||
        input == "hey there" ||
        input == "hello there" ||
        input == "hi there" ||
        input == "salam" ||
        input == "aoa" ||
        input == "assalam o alaikum" ||
        input == "assalamualaikum")
    {
        return "greeting";
    }


    // --------------------------------------------------------
    // MORNING INTENT
    // --------------------------------------------------------

    else if (input == "good morning" ||
             input == "morning" ||
             input == "good morning bot" ||
             input == "good morning chatbot")
    {
        return "morning";
    }


    // --------------------------------------------------------
    // AFTERNOON INTENT
    // --------------------------------------------------------

    else if (input == "good afternoon" ||
             input == "afternoon" ||
             input == "good afternoon bot")
    {
        return "afternoon";
    }


    // --------------------------------------------------------
    // EVENING INTENT
    // --------------------------------------------------------

    else if (input == "good evening" ||
             input == "evening" ||
             input == "good evening bot")
    {
        return "evening";
    }


    // --------------------------------------------------------
    // WELLBEING INTENT
    // --------------------------------------------------------

    else if (input == "how are you" ||
             input == "how are u" ||
             input == "how r you" ||
             input == "how r u" ||
             input == "are you okay" ||
             input == "are you fine" ||
             input == "are you doing okay" ||
             input == "how is your day" ||
             input == "how has your day been")
    {
        return "wellbeing";
    }


    // --------------------------------------------------------
    // CHATBOT INTRODUCTION INTENT
    // --------------------------------------------------------

    else if (input == "what is your name" ||
             input == "whats your name" ||
             input == "who are you" ||
             input == "tell me your name" ||
             input == "what should i call you" ||
             input == "introduce yourself")
    {
        return "introduction";
    }


    // --------------------------------------------------------
    // CHATBOT ABILITIES INTENT
    // --------------------------------------------------------

    else if (input == "what can you do" ||
             input == "what do you do" ||
             input == "what are your abilities" ||
             input == "how can you help me" ||
             input == "what can you help me with" ||
             input == "what are you capable of")
    {
        return "abilities";
    }


    // --------------------------------------------------------
    // HELP INTENT
    // --------------------------------------------------------

    else if (input == "help" ||
             input == "help me" ||
             input == "show help" ||
             input == "show me help" ||
             input == "commands" ||
             input == "options" ||
             input == "what can i ask")
    {
        return "help";
    }


    // --------------------------------------------------------
    // AI INTENT
    // --------------------------------------------------------

    else if (input == "what is ai" ||
             input == "what is artificial intelligence" ||
             input == "define ai" ||
             input == "define artificial intelligence" ||
             input == "explain ai" ||
             input == "tell me about ai" ||
             input == "what does ai mean" ||
             containsPhrase(input, "artificial intelligence meaning"))
    {
        return "ai";
    }


    // --------------------------------------------------------
    // MACHINE LEARNING INTENT
    // --------------------------------------------------------

    else if (input == "what is machine learning" ||
             input == "define machine learning" ||
             input == "explain machine learning" ||
             input == "tell me about machine learning" ||
             input == "what does machine learning mean" ||
             input == "what is ml")
    {
        return "machine_learning";
    }


    // --------------------------------------------------------
    // RULE-BASED CHATBOT INTENT
    // --------------------------------------------------------

    else if (input == "what is a rule based chatbot" ||
             input == "what is rule based chatbot" ||
             input == "what is a rule based ai" ||
             input == "how does a rule based chatbot work" ||
             input == "how do rule based chatbots work" ||
             input == "how do you work" ||
             input == "how does this chatbot work")
    {
        return "rule_based";
    }


    // --------------------------------------------------------
    // PROGRAMMING INTENT
    // --------------------------------------------------------

    else if (input == "what is programming" ||
             input == "define programming" ||
             input == "what does programming mean" ||
             input == "tell me about programming" ||
             input == "what is computer programming")
    {
        return "programming";
    }


    // --------------------------------------------------------
    // C++ INTENT
    // --------------------------------------------------------

    else if (input == "what is c++" ||
             input == "what is cpp" ||
             input == "tell me about c++" ||
             input == "define c++" ||
             input == "what does c++ mean" ||
             input == "why is c++ used")
    {
        return "cpp";
    }


    // --------------------------------------------------------
    // COMPUTER INTENT
    // --------------------------------------------------------

    else if (input == "what is a computer" ||
             input == "what is computer" ||
             input == "define computer" ||
             input == "tell me about computers" ||
             input == "what does a computer do")
    {
        return "computer";
    }


    // --------------------------------------------------------
    // HARDWARE INTENT
    // --------------------------------------------------------

    else if (input == "what is hardware" ||
             input == "define hardware" ||
             input == "what does hardware mean" ||
             input == "tell me about hardware" ||
             input == "what are computer hardware")
    {
        return "hardware";
    }


    // --------------------------------------------------------
    // SOFTWARE INTENT
    // --------------------------------------------------------

    else if (input == "what is software" ||
             input == "define software" ||
             input == "what does software mean" ||
             input == "tell me about software")
    {
        return "software";
    }


    // --------------------------------------------------------
    // THANKS INTENT
    // --------------------------------------------------------

    else if (input == "thank you" ||
             input == "thanks" ||
             input == "thank u" ||
             input == "thx" ||
             input == "thanks a lot" ||
             input == "thank you so much" ||
             input == "i appreciate it" ||
             input == "much appreciated")
    {
        return "thanks";
    }


    // --------------------------------------------------------
    // SORRY INTENT
    // --------------------------------------------------------

    else if (input == "sorry" ||
             input == "i am sorry" ||
             input == "im sorry" ||
             input == "my bad" ||
             input == "sorry about that")
    {
        return "sorry";
    }


    // --------------------------------------------------------
    // JOKE INTENT
    // --------------------------------------------------------

    else if (input == "tell me a joke" ||
             input == "tell me a funny joke" ||
             input == "make me laugh" ||
             input == "say something funny" ||
             input == "do you know a joke" ||
             input == "do you know any jokes" ||
             input == "i want a joke")
    {
        return "joke";
    }


    // --------------------------------------------------------
    // ANOTHER JOKE INTENT
    // --------------------------------------------------------

    else if (input == "another joke" ||
             input == "tell me another joke" ||
             input == "one more joke" ||
             input == "give me another joke")
    {
        return "another_joke";
    }


    // --------------------------------------------------------
    // MOTIVATION INTENT
    // --------------------------------------------------------

    else if (input == "motivate me" ||
             input == "i need motivation" ||
             input == "give me motivation" ||
             input == "say something motivating" ||
             input == "i need some motivation" ||
             input == "can you motivate me")
    {
        return "motivation";
    }


    // --------------------------------------------------------
    // STUDY INTENT
    // --------------------------------------------------------

    else if (input == "i am studying" ||
             input == "i have to study" ||
             input == "i have an exam" ||
             input == "i have exams" ||
             input == "i need to study" ||
             input == "my exams are coming" ||
             input == "i have a test")
    {
        return "study";
    }


    // --------------------------------------------------------
    // HAPPY INTENT
    // --------------------------------------------------------

    else if (input == "i am happy" ||
             input == "im happy" ||
             input == "i feel happy" ||
             input == "i am feeling good" ||
             input == "i feel good" ||
             input == "i am having a good day")
    {
        return "happy";
    }


    // --------------------------------------------------------
    // SAD INTENT
    // --------------------------------------------------------

    else if (input == "i am sad" ||
             input == "im sad" ||
             input == "i feel sad" ||
             input == "i am upset" ||
             input == "i feel upset" ||
             input == "i am not feeling good" ||
             input == "i feel bad")
    {
        return "sad";
    }


    // --------------------------------------------------------
    // TIRED INTENT
    // --------------------------------------------------------

    else if (input == "i am tired" ||
             input == "im tired" ||
             input == "i feel tired" ||
             input == "i am exhausted" ||
             input == "i feel exhausted" ||
             input == "i need rest")
    {
        return "tired";
    }


    // --------------------------------------------------------
    // GOODBYE INTENT
    // --------------------------------------------------------

    else if (isExitCommand(input))
    {
        return "goodbye";
    }


    // --------------------------------------------------------
    // UNKNOWN INTENT
    // --------------------------------------------------------

    else
    {
        return "unknown";
    }
}


// ------------------------------------------------------------
// FUNCTION: GET RESPONSE FROM KNOWLEDGE BASE
// ------------------------------------------------------------

string getResponse(string intent)
{
    if (intent == "help")
    {
        displayHelp();

        return "";
    }

    else if (intent == "unknown")
    {
        return "I am not sure how to respond to that yet. "
               "Try typing 'help' to see the things I can understand.";
    }

    else if (knowledgeBase.find(intent) != knowledgeBase.end())
    {
        return knowledgeBase[intent];
    }

    return "I am sorry, I do not have a response for that yet.";
}


// ------------------------------------------------------------
// MAIN FUNCTION
// ------------------------------------------------------------

int main()
{
    string userInput;
    string cleanInput;
    string intent;
    string response;

    bool chatbotRunning = true;

    // Display introduction
    displayWelcome();


    // --------------------------------------------------------
    // CONTINUOUS INPUT LOOP
    // --------------------------------------------------------

    while (chatbotRunning)
    {
        cout << "\nYou: ";

        getline(cin, userInput);


        // ----------------------------------------------------
        // CHECK FOR EMPTY INPUT
        // ----------------------------------------------------

        if (userInput.empty())
        {
            cout << "Bot: Please type something so I can understand you.";
            continue;
        }


        // ----------------------------------------------------
        // SANITIZE INPUT
        // ----------------------------------------------------

        cleanInput = sanitizeInput(userInput);


        // ----------------------------------------------------
        // CHECK AGAIN AFTER SANITIZATION
        // ----------------------------------------------------

        if (cleanInput.empty())
        {
            cout << "Bot: I could not understand that input. "
                    "Please try again.";
            continue;
        }


        // ----------------------------------------------------
        // EXIT STRATEGY
        // ----------------------------------------------------

        if (isExitCommand(cleanInput))
        {
            response = knowledgeBase["goodbye"];

            cout << "Bot: " << response << endl;

            chatbotRunning = false;

            continue;
        }


        // ----------------------------------------------------
        // IDENTIFY USER INTENT
        // ----------------------------------------------------

        intent = identifyIntent(cleanInput);


        // ----------------------------------------------------
        // GET RESPONSE
        // ----------------------------------------------------

        response = getResponse(intent);


        // ----------------------------------------------------
        // DISPLAY RESPONSE
        // ----------------------------------------------------

        if (!response.empty())
        {
            cout << "Bot: " << response << endl;
        }
    }


    // --------------------------------------------------------
    // PROGRAM END
    // --------------------------------------------------------

    cout << "\n============================================================\n";
    cout << "                 CHATBOT SESSION ENDED\n";
    cout << "============================================================\n";

    return 0;
}