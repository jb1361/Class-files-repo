import {Hash} from 'crypto';

export class Bloom {
    public bitset: boolean[];
    private crypto = require('crypto');
    private length: number;

    constructor(sz: string) {
        this.bitset = [];
        this.length = 0;
        this.createHash(sz);
        // You should initialize sz entries in bitset to false here
    }

    public createHash(val: string) {
        this.length += 2;
        const Hash1 = this.hash1();
        const Hash2 = this.hash2();
        this.record(this.getHashVal(Hash1, val));
        this.record(this.getHashVal(Hash2, val));
    }

    public check(val: string) {
        const Hash1 = this.hash1();
        const Hash2 = this.hash2();
        const num = this.getHashVal(Hash1, val);
        const num2 = this.getHashVal(Hash2, val);
        return this.bitset[num % this.bitsetLength()] === true && this.bitset[num2 % this.bitsetLength()] === true;
    }
    public bitsetLength(): number {
        return this.length;
    }

    private hash1(): Hash {
        return this.crypto.createHash('sha256');
    }

    private hash2(): Hash {
        return this.crypto.createHash('MD5');
    }

    private getHashVal(val: Hash, st: string) {
        val.update(st);
        return parseInt(val.digest('hex'), 10);
    }

    private record(val: number) {
        this.bitset[val % this.bitsetLength()] = true;
    }


}
