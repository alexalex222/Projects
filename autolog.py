# -*- coding: utf-8 -*-
"""
Created on Mon Jul 10 13:17:31 2017

@author: kchen
"""
import time
from bs4 import BeautifulSoup
import io
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


'''
url = 'https://thanksaton.achievers.com/login'
payload = {
    'action': 'login',
    'username': '43958',
    'password': '112358'
}

r = requests.get(url)
print(r.content)
'''

def parse_html(html_file):
    parsed_html = BeautifulSoup(html_file, 'lxml')
    teacher = parsed_html.body.find('h3', attrs={'id':'teachername'}).text
    timeMonth = parsed_html.body.find_all('div', attrs={'class':'timeMonth'})
    timeHour = parsed_html.body.find_all('div', attrs={'class':'timeHour'})
    roomAstudent = parsed_html.body.find_all('ul', attrs={'class':'roomAstudent'})
    n = len(timeMonth)
    csv_file = io.open('new_courses.csv','w',encoding = 'utf-8-sig')
    for i in range(0, n):
        csv_file.write(timeMonth[i].text)
        csv_file.write(',')
        csv_file.write(',')
        csv_file.write(timeHour[i].text)
        csv_file.write(',')
        csv_file.write(roomAstudent[i].findAll('li')[1].text[0])
        csv_file.write('\n')
    
    csv_file.close()

if __name__ == "__xxx__":
    html_file = io.open('sample.html', 'r', encoding = 'utf-8').read()
    parsed_html = BeautifulSoup(html_file, 'lxml')
    teacher = parsed_html.body.find('h3', attrs={'id':'teachername'}).text
    timeMonth = parsed_html.body.find_all('div', attrs={'class':'timeMonth'})
    timeHour = parsed_html.body.find_all('div', attrs={'class':'timeHour'})
    roomAstudent = parsed_html.body.find_all('ul', attrs={'class':'roomAstudent'})
    numStudent = roomAstudent[0].findAll('li')
    n = len(timeMonth)
    csv_file = io.open('new_courses.csv','w',encoding = 'utf-8-sig')
    for i in range(0, n):
        csv_file.write(timeMonth[i].text)
        csv_file.write(',')
        csv_file.write(',')
        csv_file.write(timeHour[i].text)
        csv_file.write(',')
        csv_file.write(roomAstudent[i].findAll('li')[1].text[0])
        csv_file.write('\n')
    
    csv_file.close()

if __name__ == "__main__":
    # create a new Firefox session
    browser = webdriver.Chrome()
    browser.maximize_window()
     
    # navigate to the application home page
    browser.get("http://t.webi.com.cn/logon")
    username = browser.find_element_by_id("username")
    password = browser.find_element_by_id("password")

    username.send_keys("alana1.801yzx")
    password.send_keys("Password01!")
    
    browser.find_element_by_class_name("loginButton").click()
    browser.get("http://t.webi.com.cn/course/list/0")
    
    start_date = browser.find_element_by_id('from')
    end_date = browser.find_element_by_id('to')
    start_date.send_keys('2017-08-06')
    end_date.send_keys('2017-08-17')
    
    browser.find_element_by_class_name('listContSearch').submit()
    html_source = browser.page_source
    parse_html(html_source)
