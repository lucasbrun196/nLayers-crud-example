import { ClubModel } from "../models/club_model"
import fs from "fs/promises"



export const findAllClubs = async (): Promise<ClubModel[]> => {
    const data = await fs.readFile("./src/data/clubs.js", "utf-8")
    const clubs: ClubModel[] = JSON.parse(data)
    return clubs
}