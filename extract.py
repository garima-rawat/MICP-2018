
import time
import json
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
i = 0
driver = webdriver.Chrome("/home/garima/Downloads/chromedriver")
driver.get('https://www.zomato.com/ncr/jungle-jamboree-connaught-place-new-delhi/reviews')
while True:
    try:
    	print i
        loadMoreButton = driver.find_element_by_css_selector('div.mtop.mbot > div')
        time.sleep(2)
        print loadMoreButton.text
        driver.execute_script("arguments[0].scrollIntoView(true);", loadMoreButton);
        loadMoreButton.click()
        time.sleep(5)
    except Exception as e:
    	print i+1
        break

driver.quit()

#reviews-container > div.notifications-content > div.res-reviews-container.res-reviews-area > div.mtop.mbot > div
#reviews-container > div.notifications-content > div.res-reviews-container.res-reviews-area > div.mtop.mbot > div
#reviews-container > div.notifications-content > div.res-reviews-container.res-reviews-area > div.mtop.mbot > div
#reviews-container > div.notifications-content > div.res-reviews-container.res-reviews-area > div.mtop.mbot > div