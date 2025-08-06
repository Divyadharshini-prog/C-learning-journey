package test;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import java.time.Duration;
import org.openqa.selenium.interactions.Actions;
import java.util.List;

public class LoginTest {

    public static void main(String[] args) {

        // Setup WebDriver
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\Computer\\Downloads\\chromedriver-win64\\chromedriver-win64\\chromedriver.exe");
        WebDriver driver = new ChromeDriver();
        driver.manage().window().maximize(); //To maximize the window
        driver.get("https://qa-iot.qmaxsys.com/");

        try {
            WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));

            // Enter phone number
            WebElement phoneField = wait.until(
                ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@type='tel']"))
            );
            phoneField.sendKeys("9600407878");

            // Click "Get OTP"
            WebElement getOtpButton = wait.until(
                ExpectedConditions.elementToBeClickable(By.xpath("/html/body/div[1]/div/form/button"))
            );
            getOtpButton.click();
            System.out.println("Clicked Get OTP");

            // Enter OTP
            WebElement otpField = wait.until(
                ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@placeholder='Enter OTP']"))
            );
            otpField.sendKeys("2024");

            // Click "Login"
            WebElement loginButton = wait.until(
                ExpectedConditions.elementToBeClickable(By.xpath("//button[text()='Login']"))
            );
            loginButton.click();

            // Wait for dashboard /main page to load (adjust wait as needed)
           // Thread.sleep(5000);
            System.out.println("Logged in. Page title is: " + driver.getTitle());

            //================ Web Navigation After Login =================//

            // Click "Devices"
            WebElement devicesButton = wait.until(
                ExpectedConditions.elementToBeClickable(
                    By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/button/span")
                )
            );
            devicesButton.click();
            System.out.println("Clicked Devices");

            // Click "Gateways"
            WebElement gatewaysButton = wait.until(
                ExpectedConditions.elementToBeClickable(
                    By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/div/ul/li[1]/a/span")
                )
            );
            gatewaysButton.click();
            System.out.println("Clicked Gateways");

            // Click Gateway Serial Number (third row; adjust if needed)
            WebElement serialNumber = wait.until(
            	    ExpectedConditions.visibilityOfElementLocated(
            	        By.xpath("//div[@class='capitalize ml-3' and text()='QGWS1022500104']")
            	    )
            	);
            Actions actions = new Actions(driver);
            actions.moveToElement(serialNumber).click().perform();
            System.out.println("Clicked on Serial Number");

            // Pause to observe (remove or adjust as needed)
            //Thread.sleep(5000);
            
          //Click gateway history 
            WebElement gwyHistory = wait.until(
            	    ExpectedConditions.visibilityOfElementLocated(
            	        By.xpath("/html/body/div[1]/main/div/div/div/div[2]/div[1]/button[2]")
            	    )
            	);
            Actions action = new Actions(driver);
            action.moveToElement(gwyHistory).click().perform();
            System.out.println("Clicked on Gateway History");
         
         // Wait for the offline period analysis table body (more robust XPath)
            WebElement offlineTableBody = wait.until(
                ExpectedConditions.visibilityOfElementLocated(
                    By.xpath("//table[.//th[contains(text(),'Start Time')]]/tbody")
                )
            );

            // Get all offline period rows
            List<WebElement> offlineRows = offlineTableBody.findElements(By.tagName("tr"));

            System.out.println("Offline Periods:");
            System.out.println("****************Gateway :IOT_QGWS1022500104****************");
            for (WebElement row : offlineRows) {
                List<WebElement> cells = row.findElements(By.tagName("td"));
                // Make sure row has expected columns: Start, End, Duration
                if (cells.size() >= 3) {
                    String startTime = cells.get(0).getText();
                    String endTime = cells.get(1).getText();
                    String duration = cells.get(2).getText();
                    
                    System.out.println("Start: " + startTime + " | End: " + endTime + " | Duration: " + duration);
                }
            }
            WebElement accountDetails = wait.until(
                    ExpectedConditions.elementToBeClickable(
                        By.xpath("/html/body/div[1]/div/div[2]/div/div[3]/ul/li/button/div/span[2]")
                    )
                );
                accountDetails.click();
                System.out.println("Clicked Account Details");
                
                WebElement logOut = wait.until(
                        ExpectedConditions.elementToBeClickable(
                            By.xpath("//*[@id=\"radix-:R3jf9laH1:\"]/div[7]")
                        )
                    );
                    logOut.click();
                    System.out.println("Clicked Log Out");
                    
                    
                    // **************************************************************
                    // Enter phone number
                    WebElement phoneFieldTwo = wait.until(
                        ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@type='tel']"))
                    );
                    phoneFieldTwo.sendKeys("9790744131");

                    // Click "Get OTP"
                    WebElement getOtpButtonTwo = wait.until(
                        ExpectedConditions.elementToBeClickable(By.xpath("/html/body/div[1]/div/form/button"))
                    );
                    getOtpButtonTwo.click();
                    System.out.println("Clicked Get OTP");

                    // Enter OTP
                    WebElement otpFieldTwo = wait.until(
                        ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@placeholder='Enter OTP']"))
                    );
                    otpFieldTwo.sendKeys("2024");

                    // Click "Login"
                    WebElement loginButtonTwo = wait.until(
                        ExpectedConditions.elementToBeClickable(By.xpath("//button[text()='Login']"))
                    );
                    loginButtonTwo.click();

                    // Wait for dashboard /main page to load (adjust wait as needed)
                   // Thread.sleep(5000);
                    System.out.println("Logged in. Page title is: " + driver.getTitle());

                    //================ Web Navigation After Login =================//

                    // Click "Devices"
                    WebElement devicesButtonTwo = wait.until(
                        ExpectedConditions.elementToBeClickable(
                            By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/button/span")
                        )
                    );
                    devicesButtonTwo.click();
                    System.out.println("Clicked Devices");

                    // Click "Gateways"
                    
                    WebElement gatewaysButtonTwo = wait.until(
                        ExpectedConditions.elementToBeClickable(
                            By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/button")
                        )
                    );
                    gatewaysButtonTwo.click();
                    //System.out.println("Clicked Gateways");
                    
                    ///html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/div/ul/li[1]/a
                    
                    WebElement gatewaysButtonTwoo = wait.until(
                            ExpectedConditions.elementToBeClickable(
                                By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/div/ul/li[1]/a/span")
                            )
                        );
                        gatewaysButtonTwoo.click();
                        System.out.println("Clicked Gateways");
                        
                        WebElement serialNumberNine = wait.until(
                        	    ExpectedConditions.visibilityOfElementLocated(
                        	        By.xpath("//div[@class='capitalize ml-3' and text()='QGWS1122400109']")
                        	        //"//div[@class='capitalize ml-3' and text()='QGWS1122400109']"
                        	    )
                        	);
                        Actions actionnumnine = new Actions(driver);
                        actionnumnine.moveToElement(serialNumberNine).click().perform();
                        System.out.println("Clicked on Serial Number");
                        
                    //Click gateway history 
                          WebElement gwyHistorytwo = wait.until(
                          	    ExpectedConditions.visibilityOfElementLocated(
                          	        By.xpath("/html/body/div[1]/main/div/div/div/div[2]/div[1]/button[2]")
                          	    )
                          	);
                          Actions actiongwynine = new Actions(driver);
                          actiongwynine.moveToElement(gwyHistorytwo).click().perform();
                          System.out.println("Clicked on Gateway History");
                       
                       // Wait for the offline period analysis table body (more robust XPath)
                          WebElement offlineTable = wait.until(
                              ExpectedConditions.visibilityOfElementLocated(
                                  By.xpath("//table[.//th[contains(text(),'Start Time')]]/tbody")
                              )
                          );
                          
                       // Get all offline period rows
                          List<WebElement> offlineRowsgwy = offlineTable.findElements(By.tagName("tr"));
                          System.out.println("*********Gateway :QGWS1122400109***********");

                          System.out.println("Offline Periods:");
                          for (WebElement row : offlineRowsgwy) {
                              List<WebElement> cells = row.findElements(By.tagName("td"));
                              // Make sure row has expected columns: Start, End, Duration
                              if (cells.size() >= 3) {
                                  String startTime = cells.get(0).getText();
                                  String endTime = cells.get(1).getText();
                                  String duration = cells.get(2).getText();
                                  System.out.println("Start: " + startTime + " | End: " + endTime + " | Duration: " + duration);
                              }
                          }
                   ///html/body/div[1]/main/div/div/div[2]/div/table/tbody/tr[3]/td[1]
                   ////html/body/div[1]/main/div/div/div[2]/div/table/tbody/tr[4]/td[1]
                   ///<div class="capitalize ml-3">QGWS1122400109</div>

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            driver.quit();
        }
    }
}

