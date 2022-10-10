#ifndef TECPTOG3_EXEPTIONS_H
#define TECPTOG3_EXEPTIONS_H

class BaseException : public std::exception {
public:
    const char *what() const noexcept override { return message_; }

protected:
    const char *message_;
};

class ErrorFileNotOpen : public BaseException {
public:
    ErrorFileNotOpen() { message_ = "File not open!"; }
};

class ErrorEmpty : public BaseException {
public:
    ErrorEmpty() { message_ = "Your variable is empty!"; }
};

class ErrorBadInput : public BaseException {
public:
    ErrorBadInput() { message_ = "Wrong input form file"; }
};

class ErrorWrongCommand : public BaseException {
public:
    ErrorWrongCommand() { message_ = "Wrong command"; }
};

class WrongIntegerInput : public BaseException {
public:
    WrongIntegerInput() { message_ = "Integer input error!"; }
};

class WrongUnsignedIntegerInput : public BaseException {
public:
    WrongUnsignedIntegerInput() { message_ = "Unsigned integer input error!"; }
};


#endif //TECPTOG3_EXEPTIONS_H
