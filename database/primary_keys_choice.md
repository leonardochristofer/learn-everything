# Introduction

“Should our keys be random or sequential?” That's the first question to answer. Only after that you should consider if your keys should be 64 bits or larger. UUIDs are 128 bits, whereas a bigint would be 64 bits.

### Reasons for using random keys

- In terms of security, randomness could be beneficial (e.g: It's more challenging to carry out an enumeration-type attack on a randomly generated value).

- Imagine of having an orders table in your database, and when the orders are displayed in your URL scheme (e.g: "/order/1"), customers can easily deduce that this is the first order. This transparency could harm your business perception by making it seem small. Additionally, it increases the vulnerability to data breaches, as attackers can predict and exploit the next record's value.

- If you're using any kind of distributed database, it is much easier to handle this with a random number. If you're using distributed systems, there's another argument to have something that's at least semi random.

### Reasons for using sequential keys

- Sequential keys are faster to generate because sequential key doesn't require access to a random number generator, you just need to increment a single field. That's pretty fast on most machines.

- Sequential keys interact much better with B-tree indexes. If you have a B-tree index, you will see that a random value interacts really badly with how the B-tree index gets structured. You will see index bloat if you're using random keys. This is a strong argument for sequential keys, if you can use them.

### Considering the size of the data type

There is an argument to be made that a 128 bit value might not be a good choice because if it's 128 bits, it has to do a little bit more memory management to handle those. This means there is overhead to 128 bits compared to 64 bits.

#### Good patterns:

- Reserve enough space for IDs. 64-bit bigserial or 128-bit uuid are both fine. 32-bit serials are never worth it.

- Think about how insertions are going to affect indexes and WAL and aim to be reasonably performant. Any of bigserial, sequential-uuids, or ulids are fine strategies.

- A downside of bigserial is that it locks you into only being able to generate IDs in one node of one database. Most people shouldn’t be looking to scale out of their database too aggressively, but having the ability to generate IDs in a distributed way (like with UUIDs) might one day turn into a pretty important feature.

- IDs that are opaque to users (i.e. not a sequence) are beneficial for security and business.

#### Not quite as definitive, but also probably good:

- ULID, having IDs that are always produced in a predictably ascending order is a nice feature for operator and end-user alike because it means that sorting by ID gives you the same order as sorting by created timestamp.

- ID prefixes like Stripe’s ch_/cus_/evt_. This is a user-friendly feature in that it allows humans to easily distinguish resource type, and makes it easy to build some useful internal tooling.

#### Bad patterns:

- The only good case for UUIDs is that they have widespread support, but that’s not a particularly strong argument. Potential performance downsides are considerable, and alternatives like smarter UUID generators or ULIDs are accessible and well-documented.

## Conclusion:

**Avoid inventing technology you don’t have to.**

References: https://brandur.org/nanoglyphs/026-ids
