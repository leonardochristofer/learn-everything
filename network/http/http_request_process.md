# How HTTP Request Works:

## User Initiates Request:
    
The process starts when a user enters a URL in the address bar or clicks on a link or button that leads to a new web page.

## DNS Resolution:

The browser first needs to translate the human-readable URL (e.g., www.example.com) into an IP address, which is the actual numerical address of the server on the internet. This translation is done through the Domain Name System (DNS) resolution.

### Here's a detailed flow of the DNS resolution process:
    
Imagine you want to visit a website, let's say "www.example.com." To access the website, your computer needs to find the IP address associated with this domain name so that it knows where to send the request. Here's what happens behind the scenes:

#### Step 1: The Request:

You type "www.example.com" in your web browser and hit Enter. Your computer now needs the IP address of "www.example.com" to proceed.

#### Step 2: Checking the Cache:

Your computer checks its local DNS cache, a temporary storage where it keeps previously resolved domain names and their corresponding IP addresses. If the IP address for "www.example.com" is already in the cache, great! The computer can proceed to access the website directly.

##### DNS Cache:

DNS caching is a mechanism used to store previously resolved DNS queries in a temporary storage area called the DNS cache. **The purpose of caching is to speed up future requests and reduce the need to repeatedly query the DNS hierarchy for frequently accessed domain names.**

When a resolver receives a DNS response, it stores the domain name and its associated IP address in the cache. If the same domain name is requested again, the resolver can **quickly provide the IP address from the cache without going through the entire DNS resolution process.**

##### Changing DNS Cache:

The DNS cache is typically managed by the operating system. As an end-user, you can change the DNS cache behavior in some cases, but it might require administrative privileges on your device. The most common ways to change the DNS cache settings:

- Flushing the DNS Cache: If you encounter DNS-related issues, you can flush the DNS cache to clear any outdated or incorrect entries. The method to flush the cache varies depending on the operating system. For example, on Windows, you can run the command ipconfig /flushdns in the Command Prompt.

It's essential to exercise caution when modifying DNS cache settings, as incorrect configurations can lead to DNS-related issues or security vulnerabilities. In most cases, DNS caching is automatically managed by the system and requires no user intervention.

###### Unseen Perspectives: the Gap Between Developers and Users

In most cases, users are not aware of such matters. For instance, when there's a need to change the IP for the same nameserver, users might unknowingly continue using the old IP. However, one potential solution to prevent this is by setting a DNS Cache Expiration Time.

Changing the DNS cache on client devices (e.g., computers, smartphones) cannot be directly done from the server side. DNS caching is a client-side function, and it is the responsibility of the DNS resolver (e.g., ISP's DNS server, local DNS cache on the client device) to manage the caching of DNS records. Server-side changes cannot directly influence or control the DNS cache on client devices.

The DNS cache on client devices is managed by the DNS resolver, which stores DNS records for a certain period (as specified by the TTL value in the DNS records) to improve DNS resolution performance and reduce the load on DNS servers. Once the TTL of a DNS record expires, the DNS resolver will automatically discard the cached record and fetch fresh DNS information from authoritative DNS servers when needed.

While server administrators and website owners cannot directly change the DNS cache on client devices, there are some strategies they can employ to influence the DNS caching behavior and minimize the impact of changes:

1. Lower TTL in Advance: Lower the Time-to-Live (TTL) value of the DNS records for the nameserver. Set the TTL to a relatively short duration, such as 15 minutes or even lower. This will reduce the amount of time that DNS resolvers and caches will retain the old IP address after the change.

2. Monitor the traffic: It's not possible to simply shut down the old IP if there's a substantial amount of traffic flowing through it.

3. Wait for Old TTL Expiry: Wait for the original TTL to expire. This ensures that DNS resolvers are now caching the updated shorter TTL value.

4. Monitor DNS Propagation: After the IP change, monitor DNS propagation to verify that the updated IP address is being distributed correctly to DNS servers worldwide. DNS propagation may take some time due to caching by various DNS servers.

By following these steps and planning the IP change carefully, you can minimize the impact on users and ensure a smooth transition to the new IP address for the same nameserver.

#### Step 3: Recursive Query:

If the IP address is not in the cache, your computer sends a request to a DNS resolver, which is like a phone book for domain names.

#### Step 4: Asking the Root Server:
        
The DNS resolver doesn't have the IP address either, so it starts the resolution process by asking the root DNS servers, which are like the root of the internet's domain name system.

#### Step 5: Directions to TLD Server:

The root DNS servers don't know the specific IP address for "www.example.com" but they can tell the resolver which Top-Level Domain (TLD) server handles the ".com" part of the domain.

#### Step 6: Asking the TLD Server:

The resolver then contacts the TLD server responsible for ".com" domains and asks for more information about "www.example.com."

#### Step 7: Directions to Authoritative Server:
        
The TLD server doesn't have the exact IP address either, but it can direct the resolver to the authoritative name servers responsible for the "example.com" domain.

#### Step 8: Asking the Authoritative Server:
        
The resolver finally contacts the authoritative name servers for "example.com" and requests the IP address for "www.example.com."

#### Step 9: The Response:

The authoritative name servers respond with the IP address of "www.example.com."

#### Step 10: Caching the Response:
        
The resolver caches the IP address it received, so it won't need to go through the entire resolution process again if someone else asks for "www.example.com" soon after.

#### Step 11: Website Access:
        
With the IP address, your computer can now access "www.example.com," and you can see the website on your browser.

That's the basic idea of how DNS resolution works. It's like a series of inquiries that start from the root of the internet's domain name system and gradually narrow down to the authoritative source for the specific domain you're looking for. The system is efficient, so once the IP address is found, it's cached for faster access in the future.

## Establishing a Connection:

Once the browser has the IP address of the server, it opens a network connection (usually using TCP/IP) to the server on the specified port (default is port 80 for HTTP and port 443 for HTTPS).

## Sending the HTTP Request:

The browser sends an HTTP request to the server. The request includes the method (e.g., GET, POST), the URL, and any additional headers or data needed for the request.

## Server Processes the Request:

The web server on the other end (e.g., Apache, Nginx) receives the HTTP request from the browser and processes it. The server looks for the requested resource on its file system or runs server-side scripts to generate the response dynamically.

## Generating the Response:

Depending on the request, the server generates an HTTP response, which typically includes a status code indicating the success or failure of the request (e.g., 200 OK, 404 Not Found) and the content (HTML, images, CSS) to be sent back to the browser.

## Sending the HTTP Response:

The server sends the HTTP response back to the browser over the same network connection established earlier.

## Receiving and Rendering the Response:
        
The browser receives the HTTP response. If the response contains HTML content, the browser parses the HTML, fetches additional resources like images, CSS, and JavaScript referenced in the HTML, and renders the web page on the user's screen.

## Rendering the Web Page:

The browser displays the rendered web page, and the user can interact with the content, click on links, fill out forms, and perform other actions.

## Closing the Connection:

Once the HTTP response is fully received, the browser closes the network connection to the server.

## Conclusion:

In summary, when a user initiates an HTTP request by entering a URL or clicking a link, the browser sends the request to the server, receives the response, and then renders the web page for the user to interact with. This process allows users to access and view web pages on the internet with the help of browsers like Chrome, Firefox, Safari, and others.