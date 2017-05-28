class AlternateString:
    def maxLength(self):
        s = input("enter string: ")
        maxLength = 1
        currentLength = 1
        startedFrom = 0
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                maxLength = max(maxLength, currentLength)
                currentLength = 1
            else:
                currentLength += 1
        maxLength = max(maxLength, currentLength)
        # print(maxLength)
        return maxLength
AlternateString().maxLength()

# # Import smtplib for the actual sending function
# import smtplib
# # Import the email modules we'll need
# from email.parser import Parser
# from email.mime.multipart import MIMEMultipart

# me = "tusharkhurana99@gmail.com"
# receiver = "manishkhurana99@gmail.com"

# message = """From: From Person <from@fromdomain.com>
# To: To Person <to@todomain.com>
# Subject: SMTP e-mail test

# This is a test e-mail message.
# """

# # Send the email via our own SMTP server.
# s = smtplib.SMTP('mail.gmail.com', 25)
# s.starttls()
# s.login("")
# s.sendmail(me, [receiver], message)
# s.quit()