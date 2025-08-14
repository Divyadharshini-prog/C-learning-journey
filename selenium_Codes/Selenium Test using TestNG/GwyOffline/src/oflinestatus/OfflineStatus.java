package oflinestatus;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.testng.annotations.BeforeClass; //testNG
import org.testng.annotations.Test;  //testNG

import java.time.Duration;
import java.util.List;

public class OfflineStatus {

    WebDriver driver;
    WebDriverWait wait;

    @BeforeClass
    public void setUp() {
        System.setProperty("webdriver.chrome.driver",
                "C:\\Users\\Computer\\Downloads\\chromedriver-win64\\chromedriver-win64\\chromedriver.exe");
        driver = new ChromeDriver();
        driver.manage().window().maximize();
        wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    }

    @Test(priority = 1)
    public void loginAndCheckGateway1() {
        driver.get("https://qa-iot.qmaxsys.com/");

        // Login for first gateway
        login("9600407878", "2024");

        // Navigate to gateway and fetch offline periods
        navigateToGateway("QGWS1022500104");

        // Logout
        logout();
    }

    @Test(priority = 2)
    public void loginAndCheckGateway2() {
        driver.get("https://qa-iot.qmaxsys.com/");

        // Login for second gateway
        login("9790744131", "2024");

        // Navigate to gateway and fetch offline periods
        navigateToGateway("QGWS1122400109");
    }

    public void login(String phoneNumber, String otp) {
        WebElement phoneField = wait.until(
                ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@type='tel']"))
        );
        phoneField.sendKeys(phoneNumber);

        WebElement getOtpButton = wait.until(
                ExpectedConditions.elementToBeClickable(By.xpath("/html/body/div[1]/div/form/button"))
        );
        getOtpButton.click();

        WebElement otpField = wait.until(
                ExpectedConditions.visibilityOfElementLocated(By.xpath("//input[@placeholder='Enter OTP']"))
        );
        otpField.sendKeys(otp);

        WebElement loginButton = wait.until(
                ExpectedConditions.elementToBeClickable(By.xpath("//button[text()='Login']"))
        );
        loginButton.click();
    }

    public void navigateToGateway(String gatewayId) {
        WebElement devicesButton = wait.until(
                ExpectedConditions.elementToBeClickable(
                        By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/button/span")
                )
        );
        devicesButton.click();

        WebElement gatewaysButton = wait.until(
                ExpectedConditions.elementToBeClickable(
                        By.xpath("/html/body/div[1]/div/div[2]/div/div[2]/div/ul/li[2]/div/ul/li[1]/a/span")
                )
        );
        gatewaysButton.click();

        WebElement serialNumber = wait.until(
                ExpectedConditions.visibilityOfElementLocated(
                        By.xpath("//div[@class='capitalize ml-3' and text()='" + gatewayId + "']")
                )
        );
        new Actions(driver).moveToElement(serialNumber).click().perform();

        WebElement gwyHistory = wait.until(
                ExpectedConditions.visibilityOfElementLocated(
                        By.xpath("/html/body/div[1]/main/div/div/div/div[2]/div[1]/button[2]")
                )
        );
        new Actions(driver).moveToElement(gwyHistory).click().perform();

        WebElement offlineTableBody = wait.until(
                ExpectedConditions.visibilityOfElementLocated(
                        By.xpath("//table[.//th[contains(text(),'Start Time')]]/tbody")
                )
        );

        List<WebElement> offlineRows = offlineTableBody.findElements(By.tagName("tr"));
        System.out.println("******** Gateway: " + gatewayId + " ********");
        for (WebElement row : offlineRows) {
            List<WebElement> cells = row.findElements(By.tagName("td"));
            if (cells.size() >= 3) {
                String startTime = cells.get(0).getText();
                String endTime = cells.get(1).getText();
                String duration = cells.get(2).getText();
                System.out.println("Start: " + startTime + " | End: " + endTime + " | Duration: " + duration);
            }
        }
    }

    public void logout() {
        WebElement accountDetails = wait.until(
                ExpectedConditions.elementToBeClickable(
                        By.xpath("/html/body/div[1]/div/div[2]/div/div[3]/ul/li/button/div/span[2]")
                )
        );
        accountDetails.click();

        WebElement logOut = wait.until(
                ExpectedConditions.elementToBeClickable(
                        By.xpath("//*[@id=\"radix-:R3jf9laH1:\"]/div[7]")
                )
        );
        logOut.click();
    }
}
