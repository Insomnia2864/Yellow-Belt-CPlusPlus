#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message);
void SendEmail(const std::string& email, const std::string& message);

class INotifier
{
public:
	INotifier() = default;

	virtual void Notify(const std::string& message) const = 0;
};

class SmsNotifier : public INotifier
{
public:
	SmsNotifier() = default;

	SmsNotifier(const std::string& phone) :
		phone_(phone)
	{}

	void Notify(const std::string& message) const override
	{
		SendSms(phone_, message);
	}
private:
	std::string phone_;
};

class EmailNotifier : public INotifier
{
public:
	EmailNotifier() = default;

	EmailNotifier(const std::string& email) :
		email_(email)
	{}

	void Notify(const std::string& message) const override
	{
		SendEmail(email_, message);
	}

private:
	std::string email_;
};
void Notify(INotifier& notifier, const std::string& message) {

	notifier.Notify(message);
}

int main() 
{
	SmsNotifier sms{ "+7-495-777-77-77" };
	EmailNotifier email{ "na-derevnyu@dedushke.ru" };

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");
	return 0;
}

void SendSms(const std::string& number, const std::string& message)
{
	std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message)
{
	std::cout << "Send '" << message << "' to e-mail " << email << std::endl;
}