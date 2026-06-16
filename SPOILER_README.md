# Schedule Optimizer - Local Setup Guide

This guide is for developers who just cloned the repo and want to run the project locally.

## 1. Prerequisites

- Git
- Node.js (LTS recommended) and npm
- PostgreSQL (local install) **or** Docker Desktop (recommended for quickest setup)

## 2. Clone the Repository

```bash
git clone <YOUR_REPO_URL>
cd schedule-optimizer
```

## 3. Setup Environment Files

### Backend env file

Create `backend/.env` with the following values:

```env
DATABASE_URL="postgresql://postgres:PostgreSQL00!@localhost:5432/schedule_optimizer?schema=public"
JWT_SECRET="k9ogv38w7@cox^oAKoqzbx!JQYBjVaYz*aG"
FRONTEND_URL="http://localhost:3000"
PORT=3001
LOG_LEVEL=info

EMAIL_HOST=smtp.gmail.com
EMAIL_PORT=587
EMAIL_USER=purduebidc@gmail.com
EMAIL_PASS="liic celr vgql lged"
```

### Frontend env file

Create `frontend/.env`:

```env
REACT_APP_API_BASE_URL=http://localhost:3001

# Optional Discord links
REACT_APP_DISCORD_MAIN_URL=https://discord.com
REACT_APP_DISCORD_CONSULTATION_URL=https://discord.com
REACT_APP_DISCORD_LAB_URL=https://discord.com
```

## 4. Start PostgreSQL

Choose one option.

### Option A (Recommended): Docker Postgres

```bash
docker run --name schedule-optimizer-db \
  -e POSTGRES_USER=postgres \
  -e POSTGRES_PASSWORD=PostgreSQL00! \
  -e POSTGRES_DB=schedule_optimizer \
  -p 5432:5432 \
  -d postgres:16
```

Anirudh Version (Win)
```bash
docker run --name schedule-optimizer-db -e POSTGRES_USER=postgres -e POSTGRES_PASSWORD=PostgreSQL00! -e POSTGRES_DB=schedule_optimizer -p 5432:5432 -d postgres:16
```

Useful commands:

```bash
docker start schedule-optimizer-db
docker stop schedule-optimizer-db
docker logs -f schedule-optimizer-db
```

### Option B: Native local Postgres

Create a DB/user matching the `DATABASE_URL` in `backend/.env`.

Example SQL:

```sql
CREATE USER postgres WITH PASSWORD 'PostgreSQL00!';
CREATE DATABASE schedule_optimizer;
GRANT ALL PRIVILEGES ON DATABASE schedule_optimizer TO postgres;
```

## 5. Setup and Run Backend

```bash
cd backend
npm install
npx prisma migrate dev
npm run seed
npm run dev
```

Notes:
- `npx prisma migrate dev` applies all existing Prisma migrations.
- `npm run seed` populates sample data and test users.
- Seed script clears existing DB data first.

Backend runs on `http://localhost:3001`.

## 6. Setup and Run Frontend

Open a second terminal:

```bash
cd frontend
npm install
npm start
```

Frontend runs on `http://localhost:3000`.

## 7. Test Accounts (Created by Seed)

- Admin: `admin@purdue.edu` / `password123`
- Student: `student@purdue.edu` / `password123`
- Additional mentor accounts are also created by the seed script (same password: `password123`)

## 8. Health Check

When backend is running, verify:

```bash
curl http://localhost:3001/health
```

Expected response includes:

```json
{"status":"ok","timestamp":"..."}
```

## 9. Common Issues

1. `P1001: Can't reach database server`
   - Confirm PostgreSQL is running on `localhost:5432`.
   - Confirm `DATABASE_URL` matches username/password/db name.

2. Prisma migrate fails
   - Ensure DB exists.
   - Re-run `npx prisma migrate dev` from `backend/`.

3. CORS errors in browser
   - Ensure backend `FRONTEND_URL` is `http://localhost:3000`.
   - Ensure frontend `REACT_APP_API_BASE_URL` is `http://localhost:3001`.

4. Registration/forgot-password errors
   - These flows require valid email SMTP settings in backend `.env`.
